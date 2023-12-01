#!/usr/bin/env python
import os

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
        self.path = path
        
        lower_filename = f.lower()
        # Calculate expense amount
        self.amount = 0.0
        split01=lower_filename.rsplit("usd")
        #print(lower_filename)
        print(split01)

        self.tax_amount = 0.0
        # check if can find a tax amount on the filename content
        
        pattern = ""
        if "tax_" in lower_filename:
            pattern = "tax_"
        elif "tax" in lower_filename:
            pattern = "tax"
        if "tax" in pattern:    
            split01 = lower_filename.rsplit(pattern)
            # now the tax part is on split01[1], in the form xxx_xxUSD
            print(f)
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
#filenames = [f for f in os.listdir(folder_path) if os.path.isfile(f)]
filenames = [f for f in os.listdir(folder_path)]
#print(filenames)
expenses = []
for f in filenames:
    exp = Expense(f, folder_path)
    #print(f)
    expenses.append(exp)

# Compute total taxes.
total = 0.0
total_taxes = 0.0
for exp in expenses:

    total_taxes += exp.tax_amount
print("Total taxes = " + str(total_taxes)) 

