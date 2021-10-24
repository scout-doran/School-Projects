import java.awt.EventQueue;
import java.util.ArrayList;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSeparator;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextField;
import javax.swing.JComboBox;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.ListModel;

import java.awt.Color;

public class Blockchain extends JFrame {

	private JPanel contentPane;
	private JTextField txtAmount;
	private JTextField textTransactionNum;
	private DefaultListModel<String> listModel;
	private JButton btnMerkleRoot;
	private JButton btnMineBlock;

	/**
	 * Launch the application.
	 */
	
	static int difficulty;
	public static void main(String[] args) {
		if (args.length > 0) 
			difficulty = Integer.parseInt(args[0]);
		else
			difficulty = 1;
		
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				Blockchain frame = new Blockchain();
				frame.setVisible(true);
			}
		});

	}

	/**
	 * Create the frame.
	 */
	
	private int transactionNum;
	private int blockNum;
	private String prevHash;
	
	private JTextField blockNumTextField;
	private JTextField prevHashTextField;
	private MerkleTree currentTree;
    private ArrayList<String> transList; //list of transactions
	private Block prevBlock;
	
	public Blockchain() {
		
		// Initialize variables
		transactionNum = 1;
		String[] names = {"Choose:", "Alice", "Bob", "Charley", "Devin", "Eve"};
		
		
		transList = new ArrayList<String>();
		blockNum = 0;
		prevHash = "";
		
		// Window
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 892, 735);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		// Label for Transaction #
		JLabel lblTransactionNo = new JLabel("Transaction #");
		lblTransactionNo.setBounds(35, 7, 111, 16);
		contentPane.add(lblTransactionNo);
		
		// Transaction #
		textTransactionNum = new JTextField(Integer.toString(transactionNum));
		textTransactionNum.setFont(new Font("Tahoma", Font.PLAIN, 14));
		textTransactionNum.setBackground(Color.WHITE);
		textTransactionNum.setEditable(false);
		textTransactionNum.setBounds(10, 31, 119, 33);
		contentPane.add(textTransactionNum);
		textTransactionNum.setColumns(10);
		
		// Label for payerCombo
		JLabel lblFrom = new JLabel("From");
		lblFrom.setBounds(180, 7, 111, 16);
		contentPane.add(lblFrom);
		
		// payerCombo
		JComboBox<String> payerCombo = new JComboBox(names);
		payerCombo.setFont(new Font("Tahoma", Font.PLAIN, 12));
		payerCombo.setBounds(139, 32, 119, 33);
		contentPane.add(payerCombo);
		
		
		// Label for paidCombo
		JLabel lblTo = new JLabel("To");
		lblTo.setBounds(315, 7, 111, 16);
		contentPane.add(lblTo);
		
		// paidCombo
		JComboBox<String> paidCombo = new JComboBox(names);
		paidCombo.setFont(new Font("Tahoma", Font.PLAIN, 12));
		paidCombo.setBounds(274, 32, 119, 33);
		contentPane.add(paidCombo);		
		
		
		// Label for Amount
		JLabel lblAmt = new JLabel("Amount (BTC)");
		lblAmt.setBounds(430, 7, 111, 16);
		contentPane.add(lblAmt);
		
		// Amount
		txtAmount = new JTextField();
		txtAmount.setFont(new Font("Tahoma", Font.PLAIN, 14));
		txtAmount.setToolTipText("");
		txtAmount.setBounds(409, 32, 119, 33);
		contentPane.add(txtAmount);
		txtAmount.setColumns(10);
		
		
		// DefaultListModel is our parameter for JList
		listModel = new DefaultListModel<String>();
		
		//DO THIS!
		// Sign Button
		JButton signBtn = new JButton("Sign");
		signBtn.setFont(new Font("Tahoma", Font.PLAIN, 18));
		signBtn.setBounds(749, 17, 119, 61);
		contentPane.add(signBtn);
		signBtn.addActionListener(new ActionListener()
		{
			// pressed button action
			public void actionPerformed(ActionEvent e)
			{
				//disable other buttons
				btnMerkleRoot.setEnabled(false);
				btnMineBlock.setEnabled(false);
				
				//create a transaction string
				String tran = Integer.toString(transactionNum) + ". " + payerCombo.getSelectedItem().toString() + " " + paidCombo.getSelectedItem().toString() + " " + txtAmount.getText() + " BTC";
				
				//add the transaction to our list
				
				transList.add(tran);
				
				//verify the digital signature of the seller and add them to our model
				listModel.addElement(tran + "  "  + DigitalSignature.verifySignature(tran));		
				
				//enable Merkle Root button
				btnMerkleRoot.setEnabled(true);

				//increment transaction number
				transactionNum++;
				textTransactionNum.setText(Integer.toString(transactionNum));
			}
		});
		
		// First separator
		JSeparator separator = new JSeparator();
		separator.setBounds(33, 100, 738, 12);
		contentPane.add(separator);
		
		// ScrollPane for JList
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(10, 128, 618, 273);
		contentPane.add(scrollPane);
		
		// JList of Transactions to display
		JList<String> list = new JList<String>(listModel);
		scrollPane.setViewportView(list);
		
		//DO THIS!
		// "Merkle Root" Button
		btnMerkleRoot = new JButton("Merkle Root");
		
		btnMerkleRoot.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//enable Merkle Root button
				btnMineBlock.setEnabled(true);			
				
				//adding a new Merkle Tree
				currentTree = new MerkleTree(transList);			
				
				//tell the user that a Merkle Tree has been created
				listModel.addElement("Merkle Tree Created...");
				JList<String> list = new JList<String>(listModel);
				scrollPane.setViewportView(list);
				
				//disable Merkle Root button
				btnMerkleRoot.setEnabled(false);
				
				//reset to a new transaction list
				transList = new ArrayList<String>();
			}
		});
		btnMerkleRoot.setBounds(690, 128, 110, 43);
		btnMerkleRoot.setEnabled(false); 
		contentPane.add(btnMerkleRoot);
		
		// Label "Block Number"
		JLabel lblBlockNumber = new JLabel("Block Number");
		lblBlockNumber.setBounds(690, 179, 111, 16);
		contentPane.add(lblBlockNumber);
		
		// Block # textField
		blockNumTextField = new JTextField("#" + blockNum);
		blockNumTextField.setEditable(false);
		blockNumTextField.setBounds(690, 205, 110, 33);
		blockNumTextField.setBackground(Color.WHITE);
		contentPane.add(blockNumTextField);
		blockNumTextField.setColumns(10);
		
		// Label "Previous Hash"
		JLabel lblPreviousHash = new JLabel("Previous Hash");
		lblPreviousHash.setBounds(689, 248, 111, 16);
		contentPane.add(lblPreviousHash);
		
		// Previous Hash textField
		for(int i = 0; i < 64; i++)
			prevHash += "0";
		prevHashTextField = new JTextField(prevHash);
		prevHashTextField.setEditable(false);
		prevHashTextField.setColumns(10);
		prevHashTextField.setBounds(690, 276, 110, 33);
		prevHashTextField.setBackground(Color.WHITE);
		contentPane.add(prevHashTextField);
		
		DefaultListModel<String> blockChainListModel = new DefaultListModel();
		
		//DO THIS!
		// "Mine Block" Button
		prevBlock = null;
		btnMineBlock = new JButton("Mine Block");
		btnMineBlock.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				//creating a new block and passing in the Block Number, the calculated Merkle Root, and the previous Block's hash
				Block block;
				
				//if this is the first block (zero based), pass null in as the previous block, otherwise, pass in the previous block
				block = new Block(blockNum, currentTree, prevBlock, difficulty);
				
				//mine the block and pass in the difficulty (maximum of 5)				
				block.mineBlock();
				
				//update the previous block
				prevBlock = block;
				
				
				//displaying the block information to the GUI
				ArrayList<String> tempArray = block.toStringArray();
				for(String str : tempArray) {
					blockChainListModel.addElement(str);
				}
				blockChainListModel.addElement("----------------------------------------------------------------------");
				
				//increment block number
				blockNum++;
				
				//displaying block
				blockNumTextField.setText("#" + blockNum);
				
				//grab the hash from the previous block
				prevHash = prevBlock.getHash();
				
				//add previous hash to be displayed in the GUI
				prevHashTextField.setText(prevHash);
				
				//disable buttons
				btnMerkleRoot.setEnabled(false);
				btnMineBlock.setEnabled(false);
				
				
				//reset the transaction #
				transactionNum = 1;
				
				//display the reset transaction number to the GUI
				textTransactionNum = new JTextField(Integer.toString(transactionNum));
				textTransactionNum.setFont(new Font("Tahoma", Font.PLAIN, 14));
				textTransactionNum.setBackground(Color.WHITE);
				textTransactionNum.setEditable(false);
				textTransactionNum.setBounds(10, 31, 119, 33);
				contentPane.add(textTransactionNum);
				textTransactionNum.setColumns(10);
				
				//clear the list of transactions
				listModel.clear();
			}
		});

		//disable Mine button
		btnMineBlock.setEnabled(false);
		btnMineBlock.setBounds(690, 342, 110, 43);
		contentPane.add(btnMineBlock);
		
		// Second separator
		JSeparator separator_1 = new JSeparator();
		separator_1.setBounds(33, 419, 715, 12);
		contentPane.add(separator_1);
		
		//create a scrollPane and display the Blockchain 
		JScrollPane scrollPaneBCList = new JScrollPane();
		scrollPaneBCList.setBounds(10, 438, 618, 250);
		contentPane.add(scrollPaneBCList);
		JList<String> blockChainList = new JList<String>(blockChainListModel);
		scrollPaneBCList.setViewportView(blockChainList);

	}
}
