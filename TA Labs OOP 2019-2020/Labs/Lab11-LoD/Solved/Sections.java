import java.util.ArrayList;

public class Sections
{
   private ArrayList<Section> sections;

   private double[] grade_constants;
   private int total_num_labs;

   //all sections should use the same random number generator
   private Random rand;
   
   /*sections class only*/
   public Sections(int num_sections, double[] grade_constants, int total_num_labs)
   {
      this.grade_constants = grade_constants;
      sections = new ArrayList<Section>();

      for (int i = 1; i <= num_sections; i++)
      {
         Section section = new Section(i, total_num_labs);
         sections.add(section);
      }

      rand = Random.getRandomNumberGenerator(); 
   }

   public int getNumSections()
   {
      return sections.size();
   }
   

   public int getNumStudents(int sectionID)
   {
      if (sectionID <= 0 || sectionID > getNumSections())
      {
         return 0;
      }

      Section section = sections.get(sectionID - 1);
      return section.getNumStudents();
   }

   //the number of labs completed by the class as a whole
   public int getNumLabs(int sectionID)
   {
      if (sectionID <= 0 || sectionID > getNumSections())
      {
         return 0;
      }

      Section section = sections.get(sectionID - 1);
      return section.getNumLabs();
   }

   //each student can have a different number of completed labs (due to withdrawals)
   public int getNumLabs(int sectionID, int studentID)
   {
      if (sectionID <= 0 || sectionID > getNumSections())
      {
         return 0;
      }

      Section section = sections.get(sectionID - 1);
      return section.getNumLabs(studentID);
   }

   public String getStudentName(int sectionID, int studentID)
   {
      if (sectionID <= 0 || sectionID > getNumSections())
      {
         return "";
      }

      Section section = sections.get(sectionID - 1);
      return section.getStudentName(studentID);
   }

   public void setGrade(int sectionID, int studentID, int labID, char grade)
   {
      if (sectionID <= 0 || sectionID > getNumSections())
      {
         return;
      }

      Section section = sections.get(sectionID - 1);
      section.setGrade(studentID, labID, grade);
   }

   public boolean isActive(int sectionID, int studentID)
   {
      if (sectionID <= 0 || sectionID > getNumSections())
      {
         return false;
      }

      Section section = sections.get(sectionID - 1);
      return section.isActive(studentID);
   }

   public boolean isPresent(int sectionID, int studentID, int labID)
   {
      if (sectionID <= 0 || sectionID > getNumSections())
      {
         return false;
      }

      Section section = sections.get(sectionID - 1);
      return section.isPresent(studentID, labID);
   }

   public void setInactive(int sectionID, int studentID)
   {
      if (sectionID <= 0 || sectionID > getNumSections())
      {
         return;
      }

      Section section = sections.get(sectionID - 1);
      section.setInactive(studentID);
   }

   public void setNotPresent(int sectionID, int studentID, int labID)
   {
      if (sectionID <= 0 || sectionID > getNumSections())
      {
         return;
      }

      Section section = sections.get(sectionID - 1);
      section.setNotPresent(studentID, labID);
   }

   public int getPartnerID(int sectionID, int studentID, int labID)
   {
      if (sectionID <= 0 || sectionID > getNumSections())
      {
         return 0;
      }

      Section section = sections.get(sectionID - 1);
      return section.getPartnerID(studentID, labID);
   }
	
   public String studentInfo(int sectionID, int studentID)
   {
      if (sectionID <= 0 || sectionID > getNumSections())
      {
         return "";
      }

      Section section = sections.get(sectionID - 1);
      return section.studentInfo(studentID);
   }

   public String partnerList(int sectionID, int labID)
   {
      if (sectionID <= 0 || sectionID > getNumSections())
      {
         return "";
      }

      Section section = sections.get(sectionID - 1);
      return section.partnerList(labID);
   }

   public void addLab(int sectionID)
   {
      if (sectionID <= 0 || sectionID > getNumSections())
      {
         return;
      }

      Section section = sections.get(sectionID - 1);
      section.addLab();
   }

   public void computePartners(int sectionID)
   {
      if (sectionID <= 0 || sectionID > getNumSections())
      {
         return;
      }

      Section section = sections.get(sectionID - 1);
      section.computePartners(rand);
   }

   public void writeFiles()
   {
      for (Section section : sections)
      {
         section.writeFile(grade_constants, total_num_labs);
      }
   }
}