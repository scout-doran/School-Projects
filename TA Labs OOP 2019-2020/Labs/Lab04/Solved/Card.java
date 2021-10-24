import java.awt.Graphics;
import java.awt.Image;

/**
 *  This class represents a standard playing Card.
 */
public class Card implements Comparable
{
   /** The face value of the Card (i.e. "Ace", "2", etc.). */
   private String face;

   /** The suit of the Card. */
   private String suit;

   /** The image associated with the Card. */
   private Image card_image;

   private static Image[] card_images = new Image[52];

   static
   {
      int count = 0;
      ImageLoader il = ImageLoader.getImageLoader();
      for (int i = 1; i <= 4; i++)
      {
         for (int j = 1; j <= 13; j++)
         {
            String image_str = i + "-" + j + ".gif";
            card_images[count] = il.getImage("images/" + image_str);
            count++;
         }
      }
   }

   /**
    *  Default constructor to create the Ace of Spades.
    */
   public Card()
   {
      this(1);
   }

   /**
    *  Constructor to create a specific card in a 52 card deck.
    *  Passing in 1 to 13 will create a Spade, 14 to 26 will create a Heart, etc.
    */
   public Card(int card_num)
   {
      int face_int;

      if (card_num < 1 || card_num > 52) //check for invalid input
      {
         suit = "Spades";
         face_int = 1; //default suit and face value
      }
      else if (card_num <= 13)
      {
         suit = "Spades";
         face_int = card_num;
      }
      else if (card_num <= 26)
      {
         suit = "Hearts";
         face_int = card_num - 13;  //get the correct face value of the card
      }
      else if (card_num <= 39)
      {
         suit = "Clubs";
         face_int = card_num - 26;
      }
      else
      {
         suit = "Diamonds";
         face_int = card_num - 39;
      }

      if (face_int == 11)  //convert numbers to appropriate strings
      {
         face = "Jack";
      }
      else if (face_int == 12)
      {
         face = "Queen";
      }
      else if (face_int == 13)
      {
         face = "King";
      }
      else if (face_int == 1)
      {
         face = "Ace";
      }
      else
      {
         face = "" + face_int;
      }

      card_image = card_images[card_num - 1];
   }

   /**
    *  Compares two Cards.
    *  The comparison is made by face first, then by suit.
    *  Cards will be sorted with Aces first (order Spades, Hearts, Clubs, Diamonds), then 2s, etc.
    */
   public int compareTo(Object other)  //sort by face first, then suit
   {
      Card card = (Card) other;
      int suitDiff = getSuitInt() - card.getSuitInt();   //spades = 1, hearts = 2, clubs = 3, diamonds = 4
      int faceDiff = getFaceInt() - card.getFaceInt();

      if (suitDiff == 0 && faceDiff == 0)
      {
         return 0;  //Cards are equal
      }
      else if (faceDiff != 0)
      {
         return faceDiff;
      }
      else  //if the Cards have the same face value, sort them by suit
      {
         return suitDiff;
      }
   }

   /**
    *  Converts the String face value to the corresponding integer (i.e. "Ace" = 1, "Jack" = 11, etc.).
    */
   public int getFaceInt()
   {
      if (face.equals("Jack"))
      {
         return 11;
      }
      else if (face.equals("Queen"))
      {
         return 12;
      }
      else if (face.equals("King"))
      {
         return 13;
      }
      else if (face.equals("Ace"))
      {
         return 1;
      }
      else
      {
         return java.lang.Integer.parseInt(face);
      }
   }

   /**
    *  Converts the String suit to a corresponding integer (i.e. "Spades" = 1, etc.).
    */
   public int getSuitInt()
   {
      if (suit.equals("Spades"))
      {
         return 1;
      }
      else if (suit.equals("Hearts"))
      {
         return 2;
      }
      else if (suit.equals("Clubs"))
      {
         return 3;
      }
      else 
      {
         return 4;
      }
   }

   /**
    *  Returns the suit.
    */
   public String getSuit()
   {
      return suit;
   }

   /**
    *  Returns the face.
    */
   public String getFace()
   {
      return face;
   }

   /**
    *  Draw the image associated with this Card to the screen.
    */
   public void draw(Graphics g, int x, int y)
   {
      g.drawImage(card_image, x, y, null);
   }

   /**
    *  Reports the card face and value.
    */
   public String toString()
   {
      return "" + face + " of " + suit;
   }

}
