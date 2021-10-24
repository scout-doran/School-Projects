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
	
	//Block Constructor.  
	public Block(int blockNum, MerkleTree merkleTree, Block previousBlock, int difficulty) {
		this.timeStamp = new Date().getTime();
		
		//update instance variables
		this.blockNum = blockNum;
		this.merkleTree = merkleTree;
		this.previousBlock = previousBlock;
		this.difficulty = difficulty;
		
		//obtain the Merkle Root
		this.merkleRoot = merkleTree.getMerkleRoot();

		//if the previous block is null, set the previous hash to 64 0's, otherwise, grab the previous block's hash
		if(previousBlock == null)
			this.previousHash = "0000000000000000000000000000000000000000000000000000000000000000";
		else
			this.previousHash = previousBlock.getHash();
		
		//start the nonce at 0
		this.nonce = 0;
		
		//obtain the number of transactions from the Merkle Tree
		this.numTrans = merkleTree.getTranList().size();
		
		//calculate and update our hash
		this.hash = calculateHash(); //Making sure we calculate the hash after we set the other values.
	}
	
	//Calculate new hash based on the block's contents
	public String calculateHash() {
		String calculatedhash = SHA256.getSHA( 
				Long.toString(timeStamp) +
				difficulty +
				previousHash +
				blockNum +
				merkleRoot
				);
		return calculatedhash;
	}
	
	//create a String display of the relevant information
	//Block #, Total Transactions, Previous Hash, Merkle Root, Hash
	public String toString() {
		return "Block #: " + blockNum + "\nTotal Transactions: " + numTrans + "\nPrev Hash: " + previousHash + "\nMerkle Root: " + merkleTree.getMerkleRoot() + "\nBlock Hash #: " + hash;
	}
	
	//returns a String ArrayList with the relevant Block information for use with the GUI
	//Block #, Total Transactions, Previous Hash, Merkle Root, Hash
	public ArrayList<String> toStringArray() {
		ArrayList<String> tempArray = new ArrayList<String>();
		tempArray.add("Block #: " + blockNum);
		tempArray.add("Total Transactions: " + numTrans);
		tempArray.add("Previous Hash: " + previousHash);
		tempArray.add("Merkle Root: " + merkleRoot);
		tempArray.add("Block Hash: " + hash);
		return tempArray;
	}
	
	//get method to return this block's hash
	public String getHash() {
		return hash;
	}
	
	//display the list of transactions
	public void displayTransactions() {
		ArrayList<String> tranList = this.merkleTree.getTranList();
		System.out.println();
		System.out.println("Transactions: ");
		for(String str : tranList) {
			System.out.println(str);
		}
		System.out.println();
	}	

	//display the list of hashed transactions
	public void displayHashTransactions() {
		System.out.println();
		ArrayList<String> hashTranList = this.merkleTree.getHashTranList();
		System.out.println("Hashed Transactions: ");
		for(String str : hashTranList) {
			System.out.println(str);
		}
		System.out.println();	
	}
	
	//Our "Proof of Work" used to mine the block
	public void mineBlock() {
		//start timer
		long startTime = System.nanoTime();
		
		//set a default difficulty if difficulty is less than 1 or greater than 5
		//if(this.difficulty > 5 || this.difficulty <= 0) this.difficulty = 1;
		
		//create a target hash String full of 0's 
		String targetHash = "0000000000";
	    
		//take a substring of the target hash, based on the difficulty passed in
		targetHash = targetHash.substring(0, this.difficulty);
		
		System.out.println("Difficulty: " + this.difficulty);
		System.out.println("Target hash: " + targetHash);
		System.out.println("Current hash: " + getHash());
		
		
		//brute force until our hash substring equals the target hash
		while (!hash.substring(0, difficulty).equals(targetHash)) {
			//System.out.println("Target hash: " + targetHash);
			//System.out.println("Current hash: " + hash);
			
			
			//recalculate our hash
			this.hash = SHA256.getSHA(hash + nonce);			
			
			//increment our nonce
			this.nonce++;
		}
	
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
