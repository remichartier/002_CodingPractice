#!/usr/bin/env python
import os
from glob import glob
import json

# execute on git_bash terminal on Windows 
folder_path = "C:\\Users\\tobefilled"
# Make a list of scenario files located in folder path



''' Setup Structure to store all the findings about the scenario, i.e.:
 - Each scenario entry has": --> Should be a list or a set, each scenario being unique.
    - Scenario name (Unique) 
    - scenario_maps (multiple) --> or set.
    - Number of actors
        - but they are 'type xxxxxx
                We do not really care about xxxxx / etc ....
                We care more about xxxxxx
'''
class Scenario:
    def __init__(self):
        self.scenario_name = ""
        self.scenario_maps = set()
        self.vehicles_auto_activated = set()
        self.vehicles_not_auto_activated = set()
        self.walkers = set()
        self.obstacles = set()
        self.splines = set()
        self.parking_spots = set()
        self.traffic_lights = set()
    
    def process_type(self, type, obj_id, activated):
        if type == 'ScenarioVehicle':
            if activated:
                self.vehicles_auto_activated.add(obj_id)
            else:
                self.vehicles_not_auto_activated.add(obj_id)            
        elif type == 'ScenarioWalker':
            self.walkers.add(obj_id)
        elif type == 'ScenarioObstacle':
            self.obstacles.add(obj_id)
        elif type == 'ScenarioSpline':
            self.splines.add(obj_id)
        elif type == 'ScenarioParkingSpot':
            self.parking_spots.add(obj_id)
        elif type == 'ScenarioTrafficLight':
            self.traffic_lights.add(obj_id)
        return
    
    def __str__(self):
        map_str = '  - maps: ' + '\n'
        for m in self.scenario_maps:
            map_str += '    - ' + m + '\n'
        return('- Scenario: ' + self.scenario_name + '\n' +
               '  - Number of vehicles_auto_activated: ' + str(len(self.vehicles_auto_activated)) + '\n' +
               '  - Number of vehicles_not_auto_activated: ' + str(len(self.vehicles_not_auto_activated)) + '\n' +
               '  - Number of walkers: ' + str(len(self.walkers)) + '\n' +
               '  - Number of obstacles: ' + str(len(self.obstacles)) + '\n' +
        #       '  - Number of splines: ' + str(len(self.splines)) + '\n' +
        #       '  - Number of parking_spots: ' + str(len(self.parking_spots)) + '\n' +
        #       '  - Number of traffic lights: ' + str(len(self.traffic_lights)) + '\n' +
               '  - Number of maps: ' + str(len(self.scenario_maps)) + '\n' +
               map_str +
                '\n' + '\n')    
        #print('List of actors IDs: ' + str(self.actors))
        #print(self.actors)
        #print('Number of actors: ' + str(len(self.actors)))
        
    def format_csv(self):
        # print in csv: map, scenario file name without root path, vehicles_auto_activated, vehicles_not_auto_activated
        lines_01 = []
        
        for m in self.scenario_maps:
            line = []
            line.append(m)
            line.append(self.scenario_name[len(folder_path)+1::])
            line.append(str(len(self.vehicles_auto_activated)))
            #print(str(len(self.vehicles_auto_activated)))
            #print(self.vehicles_auto_activated)
            #line.append(str(len(self.vehicles_not_auto_activated)))
            line.append(str(len(self.walkers)))
            lines_01.append(','.join(line))
        return(lines_01)    
        
        

#from glob import glob
results = [y for x in os.walk(folder_path) for y in glob(os.path.join(x[0], '*.json'))]

#print(results)
scenarios = []

#For each scenario
for filename in results:
    #filename = results[0]
    #print(filename[len(folder_path)+1::])
    object = Scenario()
    object.scenario_name = filename

    #print("for file: " + filename)   
    #print()



    f = open(filename)
    # returns JSON object as a dictionary
    data = json.load(f)
    # Closing file
    f.close()
    
    # Iterating through the json list
    for obj_list in data['Objects']:
        #obj_list = data['Objects']
        #print(type(obj_list)) --> list
        #print(type(obj_list[0])) --> dict
        #print(type(obj_list))  #--> dict
        
        #object.actors.add(obj_list.get("ObjectId"))
        if "Positions" in obj_list.keys():
            if obj_list.get("Positions") != None:
                for m in obj_list.get("Positions"):
                    object.scenario_maps.add(m)
                #print(obj_list.get("Positions"))
        type = obj_list.get("Type")
        auto_activated = obj_list.get("AutoActivated")
        object.process_type(type, obj_list.get("ObjectId"), auto_activated)
        

    '''
    print('Scenario: ' + object.scenario_name)    
    print('List of actors IDs: ' + str(object.actors))
    print(object.actors)
    print('Number of actors: ' + str(len(object.actors)))
    '''
    #print(object)
    #print(filename[len(folder_path)+1::])
    #print(len(object.vehicles_auto_activated))
    scenarios.append(object)
    #object = None # release, because when appending info, there are some issues.
    
# END For each scenario    
    
# Now, we have the list of all the scenarios.
# We can then print a list of map with scenarios and number of vehicles.    
# print in csv: map, scenario file name without root path, vehicles_auto_activated, vehicles_not_auto_activated

lines = []
lines.append('Map,Scenario,Vehicles_auto_activated,Walkers') # Vehicles_not_auto_activated,
for s in scenarios:
    #print(s.scenario_name[len(folder_path)+1::])
    #print(len(s.vehicles_auto_activated))
    lines.extend(s.format_csv())
for l in lines:
    print(l)

    
'''
Hi Remi,
a gentle reminder, could you kindly share any dense urban scenario and associate map details
thanks
'''