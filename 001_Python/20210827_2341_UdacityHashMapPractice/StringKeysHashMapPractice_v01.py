"""10. String Keys Practice
In this quiz, you'll write your own hash table and hash function that uses string keys. 
Your table will store strings in buckets by their first two letters, according to the 
formula below:
Hash Value = (ASCII Value of First Letter * 100) + ASCII Value of Second Letter 
You can assume that the string will have at least two letters, and the first two characters 
are uppercase letters (ASCII values from 65 to 90). You can use the Python function ord() to get the ASCII value of a letter, and chr() to get the letter associated with an ASCII value.
You'll create a HashTable class, methods to store and lookup values, and a helper function 
to calculate a hash value given a string. You cannot use a Python dictionary—only lists!
 And remember to store lists at each bucket, and not just the string itself. 
 For example, you can store "UDACITY" at index 8568 as ["UDACITY"].
Start Quiz

Provided:"""
"""Write a HashTable class that stores strings
in a hash table, where keys are calculated
using the first two letters of the string."""

SIZE_MAX = 10000
class HashTable(object):
    def __init__(self):
        self.table = [None]*SIZE_MAX

    def store(self, string):
        """Input a string that's stored in 
        the table."""
        hash_value = self.calculate_hash_value(string)
        if hash_value < SIZE_MAX and hash_value > 0:
            if self.table[hash_value] == None:
                self.table[hash_value]=[string]
            else:
                self.table[hash_value].append(string)
            #print(self.table[hash_value])
                
    def lookup(self, string):
        """Return the hash value if the
        string is already in the table.
        Return -1 otherwise."""
        hash_value = self.calculate_hash_value(string)
        if hash_value < SIZE_MAX and hash_value > 0:
            if self.table[hash_value]:
                if string in self.table[hash_value]:
                    return hash_value 
        return -1

    def calculate_hash_value(self, string):
        """Helper function to calculate a
        hash value from a string."""
        return ord(string[0])*100 + ord(string[1])
    
# Setup
hash_table = HashTable()

# Test calculate_hash_value
# Should be 8568
print(hash_table.calculate_hash_value('UDACITY'))

# Test lookup edge case
# Should be -1
print(hash_table.lookup('UDACITY'))

# Test store
hash_table.store('UDACITY')
# Should be 8568
print(hash_table.lookup('UDACITY'))

# Test store edge case
hash_table.store('UDACIOUS')
# Should be 8568
print(hash_table.lookup('UDACIOUS'))

