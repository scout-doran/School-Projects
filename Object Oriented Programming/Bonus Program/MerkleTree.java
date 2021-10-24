import java.math.BigInteger; 
import java.security.MessageDigest; 
import java.security.NoSuchAlgorithmException; 
import java.util.ArrayList;

// Java program to calculate Merkle Root 

class MerkleTree {
	
	public static ArrayList<String> CreateTree(){
		ArrayList<String> list = new ArrayList<String>();
		list.add("7246");
		list.add("9716");
		list.add("2017");
		list.add("6329");
		list.add("2831");
		list.add("1171");
		list.add("5690");
		list.add("7739");
		list.add("9463");
		list.add("8363");
		return list;
	}
		
	//add all the hashed items together 
	//hash that value and that is your merkle root
	public static String getMerkleRoot(ArrayList<String> list){
		String SHAItem = "";
		for(int i = 0; i < 10; i++)
		{
			String item = list.get(i);
			SHAItem += getSHA(item);
		}
		String merkleRoot = getSHA(SHAItem);
		return merkleRoot;
	}
	
	public static String getSHA(String input) 
	{ 

		try { 

			// Static getInstance method is called with hashing SHA 
			MessageDigest md = MessageDigest.getInstance("SHA-256"); 

			// digest() method called 
			// to calculate message digest of an input 
			// and return array of byte 
			byte[] messageDigest = md.digest(input.getBytes()); 

			// Convert byte array into signum representation 
			BigInteger no = new BigInteger(1, messageDigest); 

			// Convert message digest into hex value 
			String hashtext = no.toString(16); 

			while (hashtext.length() < 64) { 
				hashtext = "0" + hashtext; 
			} 

			return hashtext; 
		} 

		// For specifying wrong message digest algorithms 
		catch (NoSuchAlgorithmException e) { 
			System.out.println("Exception thrown"
							+ " for incorrect algorithm: " + e); 

			return null; 
		} 
	} 

	// Driver code 
	public static void main(String args[]) throws NoSuchAlgorithmException 
	{ 
		System.out.println("Root of Merkle Tree: " + getMerkleRoot(CreateTree()));
		
	} 
} 
