import java.util.Scanner;
import java.io.File;
import java.util.ArrayList;
import java.io.FileNotFoundException;
import java.util.Collections; 

import java.io.FileWriter;
import java.io.IOException;


public class sortFile{

	public static void main(String[] args){

		try {
			File fileIn = new File("a.txt");
			Scanner scanner = new Scanner(fileIn);
			ArrayList<String> lines = new ArrayList<String>();

			while (scanner.hasNextLine()) {
				lines.add(scanner.nextLine());
			}
			scanner.close();

			// now need to sort the list of strings.

			Collections.sort(lines);
			
			// now need to write array list into a file.

			try {
            	FileWriter writer = new FileWriter("b.txt", true);

            	for(String l:lines){
            		writer.write(l + "\n");
            	}
            
            	writer.close();
        	} catch (IOException e) {
            	e.printStackTrace();
        	}

			lines.clear();

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		
	}
} 

/* javac sortFile.java
	java sortFile

*/