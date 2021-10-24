import java.util.ArrayList;

//note: normally a MerkleTree would also have a way to lookup and verify the authenicity of individual transactions, although for this program we just care about calculating the Merkle Root


public class MerkleTree {
	
    private ArrayList<String> tranList; //in reality, we would want to encrypt our transaction list, although it is not necessary for our simulation purposes
    private ArrayList<String> hashTranList;
	private String root;
	
	//DO THIS
	//Merkle Tree Constructor
    public MerkleTree(ArrayList<String> tranList) {
		//update your transaction list

		
		//instantiate your hashed transaction list

		
		//add SHA 256 hashes of your transaction list to our hashed transaction list


		
    }
 
	//concatenate two strings and then calculate and return a SHA256 hash
    private String concatenateHash(String str1, String str2) {
  
  
    }
	
	//return the transaction list
	public ArrayList<String> getTranList() {

	}
	
	//returns the hashed transaction list
	public ArrayList<String> getHashTranList() {

	}
	
	//Convenience method
	//call the recursive getMerkleRoot method passing in the hashed transaction list & return the first item in the ArrayList
    public String getMerkleRoot() {
		//update and return root


    }
	
	//method to recursively calculate our Merkle Root
    private ArrayList<String> getMerkleRoot(ArrayList<String> hashTranList) {
		//grab the size of the hashed transaction list
        
 
		//if we only have a single item in the list, it is our Merkle Root (exit condition for recursion)

		
		//create and instantiate a temporary ArrayList of Strings
 
 
		//concatenate and hash each subsequent pair of transactions (use concatenateHash method)

 
		//if we do not have an even amount of transactions, concatenate the last transaction with itself & hash	
        
		
		
		//recursively return this method, passing in our temporary ArrayList (each call reduces the size of our list, until only one item remains
        
		
		
		
    }
 
 
}