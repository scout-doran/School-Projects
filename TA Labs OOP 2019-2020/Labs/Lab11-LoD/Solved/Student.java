public class Student
{
   private int studentID;
   private String name;
   private int rank;

   private Labs labs;  //stores partner IDs

   //relevant to the current lab only
   private boolean active;
   private boolean hasPartner;

   public Student(int id, String name, boolean active, int rank, Labs labs)
   {
      studentID = id;
      this.name = name;
      this.active = active;

      this.labs = labs;

      hasPartner = false;
      this.rank = rank;
   }

   public int getNumLabs()
   {
      return labs.getNumLabs();
   }

   public int getRank()
   {
      return rank;
   }

   public boolean hasPartner()
   {
      return hasPartner;
   }

   //brand new lab with default values
   public void addLab()
   {
      labs.addLab();
   }

   public void addLab(char grade, int partnerID)
   {
      labs.addLab(grade, partnerID);
   }

   //just assigned the partner for the current lab
   public void setPartnerID(int partnerID)
   {
      int labID = getNumLabs();
      labs.setPartnerID(labID, partnerID);
      hasPartner = true;
   }

   public int getPartnerID(int labID)
   {
      return labs.getPartnerID(labID);
   }

   public boolean isActive()
   {
      return active;
   }

   public void setInactive()
   {
      active = false;
   }

   public String getName()
   {
      return name;
   }

   public int getStudentID()
   {
      return studentID;
   }

   public boolean isPresent(int labID)
   {
      return labs.isPresent(labID);
   }

   public void setGrade(int labID, char grade)
   {
      labs.setGrade(labID, grade);
   }

   public char getGrade(int labID)
   {
      return labs.getGrade(labID);
   }

   public String toString()
   {
      String temp = "" + studentID + ",";
      temp += name;
      if (active)
      {
         temp += "," + "Y";
      }
      else
      {
         temp += "," + "N";
      }

      temp += "," + rank;  //new feature

      int numLabs = labs.getNumLabs();
      for (int labID = 1; labID <= numLabs; labID++)
      {
         temp += ",";
         temp += labs.getGrade(labID) + ",";

            try
            {
               temp += labs.getPartnerID(labID);  //inactive students will cause a problem here
            }
            catch (IndexOutOfBoundsException ioobe)  
            {
            }
      }

      return temp;
   }

   public char computeFinalGrade(double[] grade_constants)  //the constants to achieve each letter grade
   {
      if (!active) 
      {
         return 'W';
      }

      return labs.computeFinalGrade(grade_constants);
   }
}