import java.io.*;
import java.util.*;

public class readfile {
	
private Scanner x;

public void openfile(){
	try{
		x=new Scanner(new File("D:\\documents\\JavaProj\\testfile.txt"));
		
	}
	catch(Exception e){
		System.out.println("Couldnt Open File");
	
	}
}
public void readFile(){
	while(x.hasNext()){
		String a = x.next();
		String b = x.next();
		String c = x.next();
		String d = x.next();
		String e = x.next();
		
		System.out.printf("%s %s %s %s %s\n", a,b,c,d,e);
		
	}
}
public void closeFile(){
	x.close();
}
}
