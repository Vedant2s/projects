package first;

import java.util.Scanner;

class inputc{
	private String Name, Location, No_Plate, CarModel, CarCompany;
	   private long ContactDetails;
	   private String YearAndMake, Bodytype;
	   private float Dimension, Weigth, Price, Performance;
	   private int pucMonth; //from 1-12 month
	   private int pucYear;
	   public void inputr(){
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
	  do { System.out.println("Body type(Sedan/SUV/Hatchback/Pickup Truck/Coupe):  \t");
	   Bodytype=input.next();}while(!(Bodytype.equalsIgnoreCase("Sedan")||Bodytype.equalsIgnoreCase("SUV")||Bodytype.equalsIgnoreCase("Hatchback")||Bodytype.equalsIgnoreCase("Pickup Truck")||Bodytype.equalsIgnoreCase("Coupe")));
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
	  int choice=0,choice2=0,counterSedan=0,counterSUV=0,counterHatchback=0,counterCoupe=0,counterPickupTruck=0,temp;
	  String id;
	  do{System.out.println("Enter Your choice \n1.Entry\n2.Update\n3.Display\n4.Display your PUC details");
	  choice=input.nextInt();
	  switch(choice) {
	  case 1:
		  System.out.println("Enter the body type of the car you want to enter\n1.Sedan\n2.SUV\n3.Hatchback\n4.PickupTruck\n5.Coupe");
		  choice2=input.nextInt();
		  break;
	  case 2:
		  choice2=0;
		  System.out.println("Enter the ID of the persons car details you want to Update: ");
		  id=input.next();
		  if(id.charAt(0)=='S'||id.charAt(0)=='s') {
			  for(int i=0;i<counterSedan;i++) {
				  if((s[i].ID).equalsIgnoreCase(id)) {
					  in.inputr();
					  s[counterSedan]=new sedan(in.getName(),  in.getLocation(),  in.getNo_Plate(),  in.getCarModel(),   in.getCarCompany(), in.getContactDetails(),  in.getYearAndMake(),  in.getBodytype(), in.getDimension(), in.getWeigth(),  in.getPrice(), in.getPerformance(),  in.getpucMonth(),  in.getpucYear());
				  }
			  }
		  }
		  else if((id.substring(0,1)).equalsIgnoreCase("SU")) {
			  for(int i=0;i<counterSUV;i++) {
				  if((S[i].ID).equalsIgnoreCase(id)) {
					  in.inputr();
					  S[i]=new SUV(in.getName(),  in.getLocation(),  in.getNo_Plate(),  in.getCarModel(),   in.getCarCompany(), in.getContactDetails(),  in.getYearAndMake(),  in.getBodytype(), in.getDimension(), in.getWeigth(),  in.getPrice(), in.getPerformance(),  in.getpucMonth(),  in.getpucYear());
				  }
			  }
		  }
		  else if((id.substring(0,0)).equalsIgnoreCase("H")) {
			  for(int i=0;i<counterHatchback;i++) {
				  if((h[i].ID).equalsIgnoreCase(id)) {
					  in.inputr();
					  h[i]=new Hatchback(in.getName(),  in.getLocation(),  in.getNo_Plate(),  in.getCarModel(),   in.getCarCompany(), in.getContactDetails(),  in.getYearAndMake(),  in.getBodytype(), in.getDimension(), in.getWeigth(),  in.getPrice(), in.getPerformance(),  in.getpucMonth(),  in.getpucYear());
				  }
			  }
		  }
		  else if((id.substring(0,0)).equalsIgnoreCase("P")) {
			  for(int i=0;i<counterPickupTruck;i++) {
				  if((p[i].ID).equalsIgnoreCase(id)) {
					  in.inputr();
					  p[i]=new PickupTruck(in.getName(),  in.getLocation(),  in.getNo_Plate(),  in.getCarModel(),   in.getCarCompany(), in.getContactDetails(),  in.getYearAndMake(),  in.getBodytype(), in.getDimension(), in.getWeigth(),  in.getPrice(), in.getPerformance(),  in.getpucMonth(),  in.getpucYear());
				  }
			  }
		  }
		  else if((id.substring(0,0)).equalsIgnoreCase("C")) {
			  for(int i=0;i<counterCoupe;i++) {
				  if((c[i].ID).equalsIgnoreCase(id)) {
					  in.inputr();
					  c[i]=new Coupe(in.getName(),  in.getLocation(),  in.getNo_Plate(),  in.getCarModel(),   in.getCarCompany(), in.getContactDetails(),  in.getYearAndMake(),  in.getBodytype(), in.getDimension(), in.getWeigth(),  in.getPrice(), in.getPerformance(),  in.getpucMonth(),  in.getpucYear());
				  }
			  }
		  }
		  break;
	  case 3:
		  choice2=0;
		  System.out.println("Enter the ID of the persons car details you want to Display: ");
		  id=input.next();
		  
		  if((id.substring(0,0)).equalsIgnoreCase("S")) {
			  for(int i=0;i<counterSedan;i++) {
				  if((s[i].ID).equalsIgnoreCase(id))
				  System.out.println("Name : "+ s[i].Name +"Location : "+s[i].Location+"\nNumber plate : "+s[i].No_Plate+"Car model : "+s[i].CarModel+"\nCar Company : "+s[i].CarCompany+"Contact details : "+s[i].getContactdecrypted()+"\nYear of release : "+s[i].YearAndMake+"Body type : "+s[i].Bodytype+"\nDimension : "+s[i].Dimension+"Weight : "+s[i].Weigth+"\nPrice : "+s[i].Price+"Performance (0-60 mph in )"+s[i].Performance+"sec\n PUC month : "+s[i].pucMonth+"PUC year : "+s[i].pucYear);
			  }
			    
		  }
		  else if((id.substring(0,1)).equalsIgnoreCase("SU")) {
			  for(int i=0;i<counterSUV;i++) {
				  if((S[i].ID).equalsIgnoreCase(id))
				  System.out.println("Name : "+ S[i].Name +"Location : "+S[i].Location+"\nNumber plate : "+S[i].No_Plate+"Car model : "+S[i].CarModel+"\nCar Company : "+S[i].CarCompany+"Contact details : "+S[i].getContactdecrypted()+"\nYear of release : "+S[i].YearAndMake+"Body type : "+S[i].Bodytype+"\nDimension : "+S[i].Dimension+"Weight : "+S[i].Weigth+"\nPrice : "+S[i].Price+"Performance (0-60 mph in )"+S[i].Performance+"sec\n PUC month : "+S[i].pucMonth+"PUC year : "+S[i].pucYear);
			  }
			    
		  }
		  else if((id.substring(0,0)).equalsIgnoreCase("H")) {
			  for(int i=0;i<counterHatchback;i++) {
				  if((h[i].ID).equalsIgnoreCase(id))
				  System.out.println("Name : "+ h[i].Name +"Location : "+h[i].Location+"\nNumber plate : "+h[i].No_Plate+"Car model : "+h[i].CarModel+"\nCar Company : "+h[i].CarCompany+"Contact details : "+h[i].getContactdecrypted()+"\nYear of release : "+h[i].YearAndMake+"Body type : "+h[i].Bodytype+"\nDimension : "+h[i].Dimension+"Weight : "+h[i].Weigth+"\nPrice : "+h[i].Price+"Performance (0-60 mph in )"+h[i].Performance+"sec\n PUC month : "+h[i].pucMonth+"PUC year : "+h[i].pucYear);
			  
			    
		  }}
			  else if((id.substring(0,0)).equalsIgnoreCase("P")) {
				  for(int i=0;i<counterPickupTruck;i++) {
					  if((p[i].ID).equalsIgnoreCase(id))
					  System.out.println("Name : "+ p[i].Name +"Location : "+p[i].Location+"\nNumber plate : "+p[i].No_Plate+"Car model : "+p[i].CarModel+"\nCar Company : "+p[i].CarCompany+"Contact details : "+p[i].getContactdecrypted()+"\nYear of release : "+p[i].YearAndMake+"Body type : "+p[i].Bodytype+"\nDimension : "+p[i].Dimension+"Weight : "+p[i].Weigth+"\nPrice : "+p[i].Price+"Performance (0-60 mph in )"+p[i].Performance+"sec\n PUC month : "+p[i].pucMonth+"PUC year : "+p[i].pucYear);
				  
				    
			  }
			  }
			  else if((id.substring(0,0)).equalsIgnoreCase("C")) {
				  for(int i=0;i<counterCoupe;i++) {
					  if((c[i].ID).equalsIgnoreCase(id))
					  System.out.println("Name : "+ c[i].Name +"Location : "+c[i].Location+"\nNumber plate : "+c[i].No_Plate+"Car model : "+c[i].CarModel+"\nCar Company : "+c[i].CarCompany+"Contact details : "+c[i].getContactdecrypted()+"\nYear of release : "+c[i].YearAndMake+"Body type : "+c[i].Bodytype+"\nDimension : "+c[i].Dimension+"Weight : "+c[i].Weigth+"\nPrice : "+c[i].Price+"Performance (0-60 mph in )"+c[i].Performance+"sec\n PUC month : "+c[i].pucMonth+"PUC year : "+c[i].pucYear);
				  
				    
			  }}
		  choice2=0;
		  break;
	  case 4:
		  
			  for(int i=0;i<counterSedan;i++) {
				  if(s[i].flag==1) {
				  s[i].PucReport();
				  System.out.println("Name : "+ s[i].Name +"Location : "+s[i].Location+"\nNumber plate : "+s[i].No_Plate+"Car model : "+s[i].CarModel+"\nCar Company : "+s[i].CarCompany+"Contact details : "+s[i].getContactdecrypted());
				  }
		  }
			  for(int i=0;i<counterSUV;i++) {
				  if(S[i].flag==1)
				  {
					  S[i].PucReport();
					  System.out.println("Name : "+ S[i].Name +"Location : "+S[i].Location+"\nNumber plate : "+S[i].No_Plate+"Car model : "+S[i].CarModel+"\nCar Company : "+S[i].CarCompany+"Contact details : "+S[i].getContactdecrypted());
					  }
		  }
			  for(int i=0;i<counterHatchback;i++) {
				  if(h[i].flag==1)
				  {
					  h[i].PucReport();
					  System.out.println("Name : "+ h[i].Name +"Location : "+h[i].Location+"\nNumber plate : "+h[i].No_Plate+"Car model : "+h[i].CarModel+"\nCar Company : "+h[i].CarCompany+"Contact details : "+h[i].getContactdecrypted());
					  }
		  }
			  for(int i=0;i<counterPickupTruck;i++) {
				  if(p[i].flag==1)
				  {
					  p[i].PucReport();
					  System.out.println("Name : "+ p[i].Name +"Location : "+p[i].Location+"\nNumber plate : "+p[i].No_Plate+"Car model : "+p[i].CarModel+"\nCar Company : "+p[i].CarCompany+"Contact details : "+p[i].getContactdecrypted());
					  }
		  }
			  for(int i=0;i<counterCoupe;i++) {
				  if(c[i].flag==1)
				  {
					  c[i].PucReport();
					  System.out.println("Name : "+ c[i].Name +"Location : "+c[i].Location+"\nNumber plate : "+c[i].No_Plate+"Car model : "+c[i].CarModel+"\nCar Company : "+c[i].CarCompany+"Contact details : "+c[i].getContactdecrypted());
					  }
		  }
			  choice2=0;
		  break;
		  
	  }
	  switch(choice2) {
	  case 1:
		  in.inputr();
		  s[counterSedan]=new sedan(in.getName(),  in.getLocation(),  in.getNo_Plate(),  in.getCarModel(),   in.getCarCompany(), in.getContactDetails(),  in.getYearAndMake(),  in.getBodytype(), in.getDimension(), in.getWeigth(),  in.getPrice(), in.getPerformance(),  in.getpucMonth(),  in.getpucYear());
		  System.out.println("Do you want to update the current date?(0/1)");
		  temp=input.nextInt();
		  if(temp==1) {
			  s[counterSedan].setdate();
		  }
		  counterSedan++;
		  break;
	  case 2:
		  in.inputr();
		  S[counterSUV]=new SUV(in.getName(),  in.getLocation(),  in.getNo_Plate(),  in.getCarModel(),   in.getCarCompany(), in.getContactDetails(),  in.getYearAndMake(),  in.getBodytype(), in.getDimension(), in.getWeigth(),  in.getPrice(), in.getPerformance(),  in.getpucMonth(),  in.getpucYear());
		  System.out.println("Do you want to update the current date?(0/1)");
		  temp=input.nextInt();
		  if(temp==1) {
			  S[counterSUV].setdate();
		  }
		  counterSUV++;
		  break;
	  case 3:
		  in.inputr();
		  h[counterHatchback]=new Hatchback(in.getName(),  in.getLocation(),  in.getNo_Plate(),  in.getCarModel(),   in.getCarCompany(), in.getContactDetails(),  in.getYearAndMake(),  in.getBodytype(), in.getDimension(), in.getWeigth(),  in.getPrice(), in.getPerformance(),  in.getpucMonth(),  in.getpucYear());
		  System.out.println("Do you want to update the current date?(0/1)");
		  temp=input.nextInt();
		  if(temp==1) {
			  h[counterHatchback].setdate();
		  }
		  counterHatchback++;
		  break;
	  case 4:
		  in.inputr();
		  c[counterCoupe]=new Coupe(in.getName(),  in.getLocation(),  in.getNo_Plate(),  in.getCarModel(),   in.getCarCompany(), in.getContactDetails(),  in.getYearAndMake(),  in.getBodytype(), in.getDimension(), in.getWeigth(),  in.getPrice(), in.getPerformance(),  in.getpucMonth(),  in.getpucYear());
		  System.out.println("Do you want to update the current date?(0/1)");
		  temp=input.nextInt();
		  if(temp==1) {
			  c[counterCoupe].setdate();
		  }
		  counterCoupe++;
		  break;
	  case 5:
		  in.inputr();
		  p[counterPickupTruck]=new PickupTruck(in.getName(),  in.getLocation(),  in.getNo_Plate(),  in.getCarModel(),   in.getCarCompany(), in.getContactDetails(),  in.getYearAndMake(),  in.getBodytype(), in.getDimension(), in.getWeigth(),  in.getPrice(), in.getPerformance(),  in.getpucMonth(),  in.getpucYear());
		  System.out.println("Do you want to update the current date?(0/1)");
		  temp=input.nextInt();
		  if(temp==1) {
			  p[counterPickupTruck].setdate();
		  }
		  counterPickupTruck++;
		  break;
	  }
	  }while(choice!=0);
	  input.close();
  }

}

class CarCompany
{
   String Name, Location, No_Plate, CarModel, CarCompany;
   long ContactDetails;
   int currentMonth = 1;
   int currentYear = 2023;
    CarCompany (String Name, String Location, String No_Plate, String CarModel,String CarCompany, long ContactDetails)
  {
    this.Name = Name;
    this.Location = Location;
    this.No_Plate = No_Plate;
    this.CarModel = CarModel;
    this.CarCompany = CarCompany;
    //this.ContactDetails = ContactDetails;
    this.ContactDetails=LongEncryption.encrypt(ContactDetails);
  }
    CarCompany(){
    	
    }
    public void setdate() {
    	System.out.println("Enter the current month number(1-12)");
    	Scanner input =new Scanner(System.in);  
    	currentMonth=input.nextInt();
		System.out.println("Enter the current year");
		currentYear=input.nextInt();
    }
    public long getContactdecrypted() {
    	return LongEncryption.decrypt(ContactDetails);
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
   int flag=0;
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
    this.pucYear=pucYear;
    if(pucYear - currentYear == 0 &&currentMonth-pucMonth  >=6)
    	flag=1;	
    else if(  currentYear-pucYear == 1 &&  pucMonth-6  <=currentMonth)
    	flag=1;
    else if(  currentYear-pucYear > 1 &&  pucMonth-6  <=currentMonth)
    	flag=1;
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
    { System.out.println ("Your PUC has expired since " +
   (pucMonth - currentMonth) + " Month(s)");
    flag=1;
    }
      else if(  currentYear-pucYear == 1 &&  pucMonth-6  <=currentMonth){
          System.out.println ("Your PUC has expired since " +
  (currentMonth+6-pucMonth) + " Month(s)");
          flag=1;
      }
        else if(  currentYear-pucYear > 1 &&  pucMonth-6  <=currentMonth){
          System.out.println ("Your PUC has expired since " + (currentYear-pucYear-1)+ " Year(s) and "+(currentMonth+6-pucMonth) + " Month(s)");
          flag=1;
      }
  }
}

class sedan extends Body 
{
  //for search function all the types
  static int counter=0;
  String ID;
  static float sum = 0;
    sedan (String name, String location, String no_Plate, String carModel, String carCompany, long contactDetails,String yearAndMake, String bodytype, float dimension, float weigth, float price, float performance,int pucMonth, int pucYear) 
    {
    	 super( name,  location,  no_Plate,  carModel,   carCompany, contactDetails,  yearAndMake,  bodytype, dimension, weigth,  price, performance,  pucMonth,  pucYear);
    sum = sum + Price;
    counter++;
    ID=Character.toString('S')+counter;
  }
  public void Report ()
  {
    System.out.println ("Number of sedan sold: " + counter +
"\ntotal sale : " + sum);
  }
 
}
      class SUV extends Body
      {
static int counter=0;
String ID;
static float sum = 0;
public  SUV(String name, String location, String no_Plate, String carModel, String carCompany, long contactDetails,String yearAndMake, String bodytype, float dimension, float weigth, float price, float performance,
int pucMonth, int pucYear) 
{
	 super( name,  location,  no_Plate,  carModel,   carCompany, contactDetails,  yearAndMake,  bodytype, dimension, weigth,  price, performance,  pucMonth,  pucYear);
 sum = sum + Price;
 counter++;
 ID="SU"+counter;
}
public void Report ()
{
 System.out.println ("Number of sedan sold: " + counter +
     "\ntotal sale : " + sum);
}
      }

    class Hatchback extends Body
    {
      static int counter=0;
      String ID;
      static float sum = 0;
       public Hatchback (String name, String location, String no_Plate, String carModel, String carCompany, long contactDetails,String yearAndMake, String bodytype, float dimension, float weigth, float price, float performance,
        		int pucMonth, int pucYear) 
        {
        	 super( name,  location,  no_Plate,  carModel,   carCompany, contactDetails,  yearAndMake,  bodytype, dimension, weigth,  price, performance,  pucMonth,  pucYear);
        	sum = sum + Price;
        	counter++;
        	ID=Character.toString('H')+counter;
      }
      public void Report ()
      {
System.out.println ("Number of sedan sold: " + counter +
   "\ntotal sale : " + sum);
      }     
    }

    class PickupTruck extends Body
    {
      static int counter=0;
      String ID;
      static float sum = 0;
       public PickupTruck (String name, String location, String no_Plate, String carModel, String carCompany, long contactDetails,String yearAndMake, String bodytype, float dimension, float weigth, float price, float performance,
        		int pucMonth, int pucYear) 
        {
        	 super( name,  location,  no_Plate,  carModel,   carCompany, contactDetails,  yearAndMake,  bodytype, dimension, weigth,  price, performance,  pucMonth,  pucYear);
        	sum = sum + Price;
        	counter++;
        	ID=Character.toString('P')+counter;
      }
      public void Report ()
      {
System.out.println ("Number of sedan sold: " + counter +
   "\ntotal sale : " + sum);
      }  
    }

    class Coupe extends Body
    {
      static int counter=0;
      String ID;
      static float sum = 0;
        Coupe (String name, String location, String no_Plate, String carModel, String carCompany, long contactDetails,String yearAndMake, String bodytype, float dimension, float weigth, float price, float performance,
        		int pucMonth, int pucYear) 
        {
        	 super( name,  location,  no_Plate,  carModel,   carCompany, contactDetails,  yearAndMake,  bodytype, dimension, weigth,  price, performance,  pucMonth,  pucYear);
        	sum = sum + Price;
        	counter++;
        	ID=Character.toString('C')+counter;
      }
      public void Report ()
      {
System.out.println ("Number of sedan sold: " + counter +
   "\ntotal sale : " + sum);
      }
    }
    class LongEncryption extends CarCompany {
        private static final long ENCRYPTION_KEY = 987654321; // Encryption key

        public static long encrypt(long value) {
            return value ^ ENCRYPTION_KEY; // XOR operation with the encryption key
        }

        public static long decrypt(long encryptedValue) {
            return encryptedValue ^ ENCRYPTION_KEY; // XOR operation with the encryption key
        }

        public  void enc (){
            long originalValue = ContactDetails; // Value to encrypt

            // Encrypt the value
            long encryptedValue = encrypt(originalValue);
            System.out.println("Encrypted value: " + encryptedValue);
            ContactDetails=encryptedValue;
            // Decrypt the encrypted value
            long decryptedValue = decrypt(encryptedValue);
            System.out.println("Decrypted value: " + decryptedValue);
        }
    }
