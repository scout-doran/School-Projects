import java.util.ArrayList;
import java.util.Date;

public class Block {
	
	private int blockNum;
	private String hash;
	private MerkleTree merkleTree;
	private String merkleRoot;
	private String previousHash;
	private long timeStamp; //as number of milliseconds since 1/1/1970.
	private int difficulty;
	private int nonce;
	private int numTrans;
	private Block previousBlock; //link to previous block
	
	//DO THIS
	//Block Constructor.  
	public Block(int blockNum, MerkleTree merkleTree, Block previousBlock, int difficulty) {
		this.timeStamp = new Date().getTime();
		
		//update instance variables
		
		
		
		
		
		//obtain the Merkle Root
		this.merkleRoot = 

		//if the previous block is null, set the previous hash to 64 0's, otherwise, grab the previous block's hash



		
		//start the nonce at 0



		
		//obtain the number of transactions from the Merkle Tree



		
		//calculate and update our hash

	}
	
	//Calculate new hash based on a concatenation of the block's contents
	//i.e. timeStamp, difficulty, previous hash, block number, and merkle root
	public String calculateHash() {
		String calculatedhash = 
		
		
		
		
		
		return calculatedhash;
	}
	
	//create a String display of the relevant information
	//Block #, Total Transactions, Previous Hash, Merkle Root, Hash
	public String toString() {

	}
	
	//return a String ArrayList with the relevant Block information for use with the GUI
	//Block #, Total Transactions, Previous Hash, Merkle Root, Hash
	public ArrayList<String> toStringArray() {
		
		
		
		
		
		
	}
	
	//get method to return this block's hash
	public String getHash() {

	}
	
	//display the list of transactions
	public void displayTransactions() {

	}	

	//display the list of hashed transactions
	public void displayHashTransactions() {
		
	}
	
	//Our "Proof of Work" used to mine the block
	public void mineBlock() {
		//start timer
		long startTime = System.nanoTime();
		
		//set a default difficulty if difficulty is less than 1 or greater than 5

		
		//create a target hash String full of 0's 

	    
		//take a substring of the target hash, based on the difficulty passed in

		
		
		
		//brute force until our hash substring equals the target hash (while loop)
		//you will need to update our hash to equal a SHA256 hash of our block hash concatentated with our nonce value
	    //make sure to increment your nonce each time
	
	
	
	
	
	
	
	
	
	
	
	
	
		//calculate and display runtime
		long endTime   = System.nanoTime();
		long totalTime = endTime - startTime;
		double seconds = (double)totalTime / 1000000000.0;
		int minutes = (int)seconds / 60;
		if (minutes > 0) 
			seconds = seconds % 60;
		System.out.println("Total Time: " + minutes + " minute(s) " + seconds + " seconds");
		
		//display the list of transactions & hashes
		displayTransactions();
		displayHashTransactions();
	}
		
}
