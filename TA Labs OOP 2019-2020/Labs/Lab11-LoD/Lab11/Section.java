
public class Section
{
   private int sectionID;
   private Students students;
   private String file;

   public Section(int sectionID, int total_num_labs)
   {
      this.sectionID = sectionID;
      file = "section" + sectionID + ".txt";
      students = new Students(file, total_num_labs);
   }

   //DO THIS
   //several short methods must be implemented (note: some have been done, see below)














   //no work below this point
   public void computePartners(Random rand)
   {
      students.computePartners(rand);
   }

   public void writeFile(double[] grade_constants, int total_num_labs)
   {
      students.writeFile(file, grade_constants, total_num_labs);
   }
}