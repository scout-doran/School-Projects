
public class LabManagerDriver
{
   //entry point
   public static void main(String[] args)
   {
      double[] grade_constants = new double[5];
      grade_constants[0] = 13.0; //required total points for an 'A'
      grade_constants[1] = 10.5;
      grade_constants[2] = 7.0;
      grade_constants[3] = 3.25;
      grade_constants[4] = 2;    //number of Fs on individual labs that will trigger an automatic 'F' for the class
      int total_num_labs = 14;
      int num_sections = 1;

      LabManagerView manager = new LabManagerView(800, 850, "Lab Manager", num_sections, grade_constants, total_num_labs);
   }
}