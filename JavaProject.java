package first;
class globall{
    public int currentMonth = 1;
    public int currentYear = 2023;
}
public class helloWorld
{

  public static void main (String[]args)
  {


  }

}
class CarCompany
{
   String Name, Location, No_Plate, CarModel, CarCompany;
   long ContactDetails;
    CarCompany (String Name, String Location, String No_Plate, String CarModel,String CarCompany, long ContactDetails)
  {
    this.Name = Name;
    this.Location = Location;
    this.No_Plate = No_Plate;
    this.CarModel = CarModel;
    this.CarCompany = CarCompany;
    this.ContactDetails = ContactDetails;
  }
}

class Body extends CarCompany
{
  //for inserting data and editing the entered value
  //exclusively for making a report on statistical data
   String YearAndMake, Bodytype;
   float Dimension, Weigth, Price, Performance;
   int pucMonth; //from 1-12 month
   int pucYear;
    Body (String Name, String Location, String No_Plate, String CarModel,String CarCompany, long ContactDetails, String YearAndMake,String Bodytype, float Dimension, float Weigth, float Price,float Performance, int pucMonth, int pucYear)
  {
    this.YearAndMake = YearAndMake;
    this.Bodytype = Bodytype;
    this.Dimension = Dimension;
    this.Weigth = Weigth;
    this.Price = Price;
    this.Performance = Performance;
    this.pucMonth = pucMonth;
    super (String Name, String Location, String No_Plate, String CarModel,String CarCompany, long ContactDetails);
  }
    public void PucReport ()
  {
    if ( currentYear-pucYear == 0 &&  currentMonth-pucMonth  <6)
      {
System.out.println ("Your PUC is going to expire in " +
  6-(currentMonth-pucMonth) + " Month(s)");
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
          System.out.println ("Your PUC has expired since " +
          (currentYear-pucYear-1)+" Year(s) and "
  (currentMonth+6-pucMonth) + " Month(s)");
      }
  }
}

class sedan extends Body
{
  //for search function all the types
  static int counter;
  String ID;
  static float sum = 0;
    sedan (String Name, String Location, String No_Plate, String CarModel,
  String CarCompany, long ContactDetails, String YearAndMake,
  String Bodytype, float Dimension, float Weigth, float Price,
  float Performance, int pucMonth, int pucYear)
  {
    sum = sum + Price;
    super (String Name, String Location, String No_Plate, String CarModel,
  String CarCompany, long ContactDetails, String YearAndMake,
  String Bodytype, float Dimension, float Weigth, float Price,
  float Performance, int pucMonth, int pucYear);
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
 sum = sum + Price;
 super (String Name, String Location, String No_Plate,
String CarModel, String CarCompany, long ContactDetails,
String YearAndMake, String Bodytype, float Dimension,
float Weigth, float Price, float Performance, int pucMonth,
int pucYear);
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
sum = sum + Price;
super (String Name, String Location, String No_Plate, String CarModel,
      String CarCompany, long ContactDetails, String YearAndMake,
      String Bodytype, float Dimension, float Weigth, float Price,
      float Performance, int pucMonth, int pucYear);
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
sum = sum + Price;
super (String Name, String Location, String No_Plate, String CarModel,
      String CarCompany, long ContactDetails, String YearAndMake,
      String Bodytype, float Dimension, float Weigth, float Price,
      float Performance, int pucMonth, int pucYear);
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
sum = sum + Price;
super (String Name, String Location, String No_Plate, String CarModel,
      String CarCompany, long ContactDetails, String YearAndMake,
      String Bodytype, float Dimension, float Weigth, float Price,
      float Performance, int pucMonth, int pucYear);
      }
      public void Report ()
      {
System.out.println ("Number of sedan sold: " + counter +
   "\ntotal sale : " + sum);
      }
     
    }
