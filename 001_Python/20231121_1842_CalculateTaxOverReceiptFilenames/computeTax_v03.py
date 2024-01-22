#!/usr/bin/env python
import os
import zipfile


# v02: Open zip file, extract "/docs/036 DepensesDomestiques" file names, extract tax amounts again.
zip_file_path = "/home/remi/Documents/copiedHomePC"
zip_files = ["20230603_1619_DocsTableur.zip", "20231219_2242_DocsTableur.zip"]
#zip_files = ["20231219_2242_DocsTableur.zip"] # problem happening in this .zip file ...
# due to file 20230825_0234_LozanoCarService_SwayBarReplacementBrakeFluid_637_20USD_Tax_xx_xxUSD.jpg
DEPENSESDOMESTIQUES_FOLDER = "docs/036 DepensesDomestiques"
YEAR = "2023"
other_files_to_process = [
    "20230106_2327_Costco_71_72USD_Tax_2_79USD.jpg",
    "20230112_1908_InAndOutRemiCelestinClara_31_59USD_Tax_2_64USD.jpg",
    "20230112_1909_InAndOut_SundaysClaraCelestin_TravelRewards_6_44USD_Tax_0_54USD.jpg",
    "20230114_1913_SmartAndFinal_17_01USD_Tax_0_44USD.jpg",
    "20230121_1955_WalgreensCoughSyropRemi_14_18USD_Tax_1_19USD.jpg",
    "20230126_1953_InAndOutRemiCelestinClara_31_59USD_Tax_2_64USD.jpg",
    "20230127_1951_Costco_87_88USD_Tax_2_28USD.jpg",
    "20230202_2246_InAndOut_31_59USD_Tax_2_64USD.jpg",
    "20230204_2242_SmartAndFinal_22_41USD_Tax_0_44USD.jpg",
    "20230209_2240_InAndOutBurger_31_59USD_Tax_2_64USD.jpg",
    "20230211_2231_SmartAndFinal_11_63USD_Tax_0_44USD.jpg",
    "20230216_0557_ArmadilloWillysEnfantsAnniversaireCelestin_72_66USD_Tax_5_34USD.jpg",
    "20230223_0551_InAndOutBurgerEnfants_31_59USD_Tax_2_64USD.jpg",
    "20230226_0549_SmartAndFinal_17_02USD_Tax_0_44USD.jpg",
    "20230302_0544_InAndOutEnfants_31_59USD_Tax_2_64USD.jpg",
    "20230311_0507_SmartAndFinal_18_81USD_Tax_0_44USD.jpg",
    "20230311_0727_InAndOutIceCreamChildren_6_44USD_Tax_0_54USD.jpg",
    "20230311_0727_InAndOutWithChildren_31_59USD_Tax_2_64USD.jpg",
    "20230314_0504_SubwayClara_21_97USD_Tax_1_54USD.jpg",
    "20230317_0502_Costco_63USD_Tax_1_28USD.jpg",
    "20230502_2215_Order details - WalmartcomInnerTubeBycicleClaraTwo700x35c_14_13USD_Tax_1_18USD.pdf"]

# Scroll voyages, voitures, divers folders to find some tax expenses as well, both on .zip and current folders, GoogleFi, Utilities

# execute on git_bash terminal on Ubuntu 
folder_path = "/home/remi/Documents/tocopyhomepc/docs/036 DepensesDomestiques"
# Make a list of scenario files located in folder path

''' Setup Structure to store 
- Filename
- Path
- Amout
- Tax amount

Export to .csv file.
'''
class Expense:
    def __init__(self, fname, path):
        self.filename = fname
        #print(fname)
        self.path = path
        
        lower_filename = fname.lower()
        # Calculate expense amount
        self.amount = 0.0
        split01=lower_filename.rsplit("usd")
        #print(lower_filename)
        #print(split01)

        self.tax_amount = 0.0
        # check if can find a tax amount on the filename content
        
        pattern = ""
        if "tax_" in lower_filename:
            pattern = "tax_"
        elif "tax" in lower_filename:
            pattern = "tax"
        if "tax" in pattern:
            if "tax " not in lower_filename:    
                split01 = lower_filename.rsplit(pattern)
                # now the tax part is on split01[1], in the form xxx_xxUSD
                #print(f)
                #print(split01[1])
                # remove file extentions from split01[1]
                split02 = split01[1].rsplit(".")
                #print(split02[0])
                # split usd to only get xxx_xx
                split03 = split02[0].rsplit("usd")
                #print(split03[0])
                # Replace _ in . in split03[0]
                self.tax_amount = float(split03[0].replace('_','.'))
                #print(str(self.tax_amount))
    
    
    def __str__(self):
        return(self.filename + ',' +
               self.path + ',' +
               str(self.amount) + ',' +
               str(self.tax_amount) +
                '\n')    
        
# Read file names in current folder.
print('* Processing file names in current folder ' + folder_path + '...')
#filenames = [f for f in os.listdir(folder_path) if os.path.isfile(f)]
filenames = [f for f in os.listdir(folder_path) if "usd" in f.lower()]
#print(filenames)
expenses = []
for f in filenames:
    exp = Expense(f, folder_path)
    #print(f)
    expenses.append(exp)
    

# Add files from zip files
# To unzip files in Python, you can use the built-in zipfile module's extractall() function. This module provides a simple and efficient way to handle zip files in Python. In this example, we import the zipfile module and use the ZipFile class to open the zip file in read mode ('r').

for zip_file in zip_files:
    print('* Processing file ' + zip_file + '...')
    with zipfile.ZipFile(zip_file_path + '/' + zip_file, mode="r") as archive:
        for filename in archive.namelist():
        	if DEPENSESDOMESTIQUES_FOLDER in filename and 'usd' in filename.lower() and 'xx_xx' not in filename.lower():
        	    #print(filename)
        	    # split folder from filename
        	    strip1 = filename[len(DEPENSESDOMESTIQUES_FOLDER) + 1::]
        	    #print(strip1)
        	    # Filter only 2023 expenses
        	    if YEAR in strip1[0:4]:
        	        exp = Expense(strip1, DEPENSESDOMESTIQUES_FOLDER)
        	        expenses.append(exp)
        	    #print(exp.tax_amount)

# add corrections files from .zip files:

for filename in other_files_to_process:
    exp = Expense(filename, DEPENSESDOMESTIQUES_FOLDER)
    expenses.append(exp)
    

# Compute total taxes.
total = 0.0
total_taxes = 0.0
for exp in expenses:

    total_taxes += exp.tax_amount
print("Total Sales taxes for year " + YEAR + " = " + str(round(total_taxes,2)) + 'USD') 

