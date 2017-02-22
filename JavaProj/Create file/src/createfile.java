import java.io.*;
import java.lang.*;
import java.util.*;

public class createfile {

	private Formatter x;
	
	public void openFile(){
		try{
			x= new Formatter("chrisbeyer.txt");
		}
		catch(Exception e){
			System.out.println("There has been an error");
		}
	}
	
	public void addRecords(){
		x.format("%s%s%s", "21","Chris","Beyer");
	}
	
	public void closeFile(){
		x.close();
	}
	
	}
