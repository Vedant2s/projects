package first;
//class globall{
//    public static int currentMonth = 1;
//    public static int currentYear = 2023;
//}
import java.util.Scanner;
class inputc{
	private String Name, Location, No_Plate, CarModel, CarCompany;
	   private long ContactDetails;
	   private String YearAndMake, Bodytype;
	   private float Dimension, Weigth, Price, Performance;
	   private int pucMonth; //from 1-12 month
	   private int pucYear;
	   void inputr(){
	   Scanner input =new Scanner(System.in);
	   System.out.print("Enter the following data \t");
	   System.out.print("Name: \t");
	   Name=input.next();
	   System.out.print("Location: \t");
	   Location=input.next();
	   System.out.print("Number plate: \t");
	   No_Plate=input.next();
	   System.out.println("Car model name:  \t");
	   CarModel=input.next();
	   System.out.print("Car company name:  \t");
	   CarCompany=input.next();
	   System.out.print("Contact number:  \t");
	   ContactDetails=input.nextLong();
	   System.out.println("Manufacturing year:  \t");
	   YearAndMake=input.next();
	   System.out.println("Body type(Sedan/SUV/Hatchback/Pickup Truck/Coupe):  \t");
	   Bodytype=input.next();
	   System.out.print("Dimension(in m):  \t");
	   Dimension=input.nextFloat();
	   System.out.print("Weigth(in Kg):  \t");
	   Weigth=input.nextFloat();
	   System.out.println("Price(in terms of grand(s)$)  \t");
	   Price=input.nextFloat();
	   System.out.print("Performance(from 0-60mph in sec)  \t");
	   Performance=input.nextFloat();
	   System.out.print("PUC issue month(from 1 to 12 ):  \t");
	   pucMonth=input.nextInt();
	   System.out.print("PUC issue Year:  \t");
	   pucYear=input.nextInt();
}
	   public String getName() {
		   return Name;
	   }
	   public String getLocation() {
		   return Location;
	   }
	   public String getCarModel() {
		   return CarModel;
	   }
	   public String getCarCompany() {
		   return CarCompany;
	   }
	   public String getYearAndMake() {
		   return YearAndMake;
	   }
	   public String getBodytype() {
		   return Bodytype;
	   }
	   public String getNo_Plate() {
		   return No_Plate;
	   }
	   public float getDimension() {
		   return Dimension;
	   }
	   public float getWeigth() {
		   return Weigth;
	   }
	   public float getPrice() {
		   return Price;
	   }
	   public float getPerformance() {
		   return Performance;
	   }
	   public int getpucMonth() {
		   return pucMonth;
	   }
	   public int getpucYear() {
		   return pucYear;
	   }
	   public long getContactDetails() {
		   return ContactDetails;
	   }
}
public class helloWorld
{
	 
  public static void main (String[]args)
  {
	  Scanner input =new Scanner(System.in);
	  System.out.println("lol");
	  inputc in=new inputc();
	  sedan[] s=new sedan[100];
	  SUV[] S=new SUV[100];
	  Hatchback[] h=new Hatchback[100];
	  PickupTruck[] p=new PickupTruck[100];
	  Coupe[] c=new Coupe[100];
	  int choice=0,choice2=0,counterSedan=0,counterSUV=0,counterHatchback=0,counterCoupe=0,counterPickupTruck=0;
	  do{System.out.println("Enter Your choice \n1.Entry\n2.Update\n3.Display");
	  switch(choice) {
	  case 1:
		  System.out.println("Enter the body type of the car you want to enter\n1.Sedan\n2.SUV\n3.Hatchback\n4.PickupTruck\n5.Coupe");
		  choice2=input.nextInt();
		  break;
	  case 2:
		  break;
	  case 3:
		  break;
	  }
	  switch(choice2) {
	  case 1:
		  in.inputr();
		  s[counterSedan].sedan(in.getName(),  in.getLocation(),  in.getNo_Plate(),  in.getCarModel(),   in.getCarCompany(), in.getContactDetails(),  in.getYearAndMake(),  in.getBodytype(), in.getDimension(), in.getWeigth(),  in.getPrice(), in.getPerformance(),  in.getpucMonth(),  in.getpucYear());
		  counterSedan++;
		  break;
	  case 2:
		  in.inputr();
		  S[counterSUV].SUV(in.getName(),  in.getLocation(),  in.getNo_Plate(),  in.getCarModel(),   in.getCarCompany(), in.getContactDetails(),  in.getYearAndMake(),  in.getBodytype(), in.getDimension(), in.getWeigth(),  in.getPrice(), in.getPerformance(),  in.getpucMonth(),  in.getpucYear());
		  counterSUV++;
		  break;
	  case 3:
		  in.inputr();
		  h[counterHatchback].Hatchback(in.getName(),  in.getLocation(),  in.getNo_Plate(),  in.getCarModel(),   in.getCarCompany(), in.getContactDetails(),  in.getYearAndMake(),  in.getBodytype(), in.getDimension(), in.getWeigth(),  in.getPrice(), in.getPerformance(),  in.getpucMonth(),  in.getpucYear());
		  counterHatchback++;
		  break;
	  case 4:
		  in.inputr();
		  c[counterCoupe].Coupe(in.getName(),  in.getLocation(),  in.getNo_Plate(),  in.getCarModel(),   in.getCarCompany(), in.getContactDetails(),  in.getYearAndMake(),  in.getBodytype(), in.getDimension(), in.getWeigth(),  in.getPrice(), in.getPerformance(),  in.getpucMonth(),  in.getpucYear());
		  counterCoupe++;
		  break;
	  case 5:
		  in.inputr();
		  p[counterPickupTruck].PickupTruck(in.getName(),  in.getLocation(),  in.getNo_Plate(),  in.getCarModel(),   in.getCarCompany(), in.getContactDetails(),  in.getYearAndMake(),  in.getBodytype(), in.getDimension(), in.getWeigth(),  in.getPrice(), in.getPerformance(),  in.getpucMonth(),  in.getpucYear());
		  counterPickupTruck++;
		  break;
	  }
	  }while(choice!=0);
  }

}
class CarCompany
{
   String Name, Location, No_Plate, CarModel, CarCompany;
   long ContactDetails;
   static int currentMonth = 1;
   static int currentYear = 2023;
    CarCompany (String Name, String Location, String No_Plate, String CarModel,String CarCompany, long ContactDetails)
  {
    this.Name = Name;
    this.Location = Location;
    this.No_Plate = No_Plate;
    this.CarModel = CarModel;
    this.CarCompany = CarCompany;
    this.ContactDetails = ContactDetails;
  }
    CarCompany(){
    	
    }
    //resale method
}

class Body extends CarCompany
{
  //for inserting data and editing the entered value
  //exclusively for making a report on statistical data
   String YearAndMake, Bodytype;
   float Dimension, Weigth, Price, Performance;
   int pucMonth; //from 1-12 month
   int pucYear;
   //int extra=currentYear;
    Body (String Name, String Location, String No_Plate, String CarModel,String CarCompany, long ContactDetails, String YearAndMake,String Bodytype, float Dimension, float Weigth, float Price,float Performance, int pucMonth, int pucYear)
  {
    	super(Name, Location, No_Plate, CarModel, CarCompany,  ContactDetails);
    this.YearAndMake = YearAndMake;
    this.Bodytype = Bodytype;
    this.Dimension = Dimension;
    this.Weigth = Weigth;
    this.Price = Price;
    this.Performance = Performance;
    this.pucMonth = pucMonth;
  }
    Body(){
    	
    }
    public void PucReport ()
  {
    if ( currentYear-pucYear == 0 &&  currentMonth-pucMonth  <6)
      {
System.out.println ("Your PUC is going to expire in " +  (6-(currentMonth-pucMonth)) + " Month(s)");
      }
      else if(  currentYear-pucYear == 1 &&  pucMonth-6  >currentMonth){
          System.out.println ("Your PUC is going to expire in " +
  (pucMonth-currentMonth-6) + " Month(s)");
      }
    else if(pucYear - currentYear == 0 &&currentMonth-pucMonth  >=6)
    System.out.println ("Your PUC has expired since " +
   (pucMonth - currentMonth) + " Month(s)");
     
      else if(  currentYear-pucYear == 1 &&  pucMonth-6  <=currentMonth){
          System.out.println ("Your PUC has expired since " +
  (currentMonth+6-pucMonth) + " Month(s)");
      }
        else if(  currentYear-pucYear > 1 &&  pucMonth-6  <=currentMonth){
          System.out.println ("Your PUC has expired since " + (currentYear-pucYear-1)+ " Year(s) and "+(currentMonth+6-pucMonth) + " Month(s)");
      }
  }
}

class sedan extends Body 
{
  //for search function all the types
  static int counter;
  String ID;
  static float sum = 0;
    sedan (String Name, String Location, String No_Plate, String CarModel,String CarCompany, long ContactDetails, String YearAndMake, String Bodytype, float Dimension, float Weigth, float Price,float Performance, int pucMonth, int pucYear)
  {
    	super( Name,  Location,  No_Plate,  CarModel,   CarCompany, ContactDetails,  YearAndMake,  Bodytype, Dimension, Weigth,  Price, Performance,  pucMonth,  pucYear);
    sum = sum + Price;
  }
  public void Report ()
  {
    System.out.println ("Number of sedan sold: " + counter +
"\ntotal sale : " + sum);
  }
 
}
      class SUV extends Body
      {
static int counter;
String ID;
static float sum = 0;
 SUV (String Name, String Location, String No_Plate, String CarModel,
      String CarCompany, long ContactDetails, String YearAndMake,
      String Bodytype, float Dimension, float Weigth, float Price,
      float Performance, int pucMonth, int pucYear)
{
	 super( Name,  Location,  No_Plate,  CarModel,   CarCompany, ContactDetails,  YearAndMake,  Bodytype, Dimension, Weigth,  Price, Performance,  pucMonth,  pucYear);
 sum = sum + Price;
}
public void Report ()
{
 System.out.println ("Number of sedan sold: " + counter +
     "\ntotal sale : " + sum);
}

      }

    class Hatchback extends Body
    {
      static int counter;
      String ID;
      static float sum = 0;
        Hatchback (String Name, String Location, String No_Plate,
  String CarModel, String CarCompany, long ContactDetails,
  String YearAndMake, String Bodytype, float Dimension,
  float Weigth, float Price, float Performance, int pucMonth,
  int pucYear)
      {
        	super( Name,  Location,  No_Plate,  CarModel,   CarCompany, ContactDetails,  YearAndMake,  Bodytype, Dimension, Weigth,  Price, Performance,  pucMonth,  pucYear);sum = sum + Price;
      }
      public void Report ()
      {
System.out.println ("Number of sedan sold: " + counter +
   "\ntotal sale : " + sum);
      }
     
    }

    class PickupTruck extends Body
    {
      static int counter;
      String ID;
      static float sum = 0;
        PickupTruck (String Name, String Location, String No_Plate,
    String CarModel, String CarCompany, long ContactDetails,
    String YearAndMake, String Bodytype, float Dimension,
    float Weigth, float Price, float Performance,
    int pucMonth, int pucYear)
      {
        	super( Name,  Location,  No_Plate,  CarModel,   CarCompany, ContactDetails,  YearAndMake,  Bodytype, Dimension, Weigth,  Price, Performance,  pucMonth,  pucYear);sum = sum + Price;
      }
      public void Report ()
      {
System.out.println ("Number of sedan sold: " + counter +
   "\ntotal sale : " + sum);
      }
     
    }

    class Coupe extends Body
    {
      static int counter;
      String ID;
      static float sum = 0;
        Coupe (String Name, String Location, String No_Plate, String CarModel,
      String CarCompany, long ContactDetails, String YearAndMake,
      String Bodytype, float Dimension, float Weigth, float Price,
      float Performance, int pucMonth, int pucYear)
      {
        	super( Name,  Location,  No_Plate,  CarModel,   CarCompany, ContactDetails,  YearAndMake,  Bodytype, Dimension, Weigth,  Price, Performance,  pucMonth,  pucYear);sum = sum + Price;
      }
      public void Report ()
      {
System.out.println ("Number of sedan sold: " + counter +
   "\ntotal sale : " + sum);
      }
     
    }
