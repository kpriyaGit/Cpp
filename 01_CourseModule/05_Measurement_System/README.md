# Measurement System (Module Exam Winter Semester 2019)

Topic of this exam is the handling of measurement values from some sensor such as a temperature or humidity sensor.

![Figure 1 - Class Diagram](./images/Class_Diag.JPG)

The diagram shows only the classes and their relationships. The attributes and methods are found in the class definitions.

## Exercise 1 : Create the Measurement Database

a) Define class Measurement with its attribute timestamp. The attribute holds the number of minutes since midnight (00:00). Declare and implement the following methods:
	◦ Measurement: Initialises the attribute with the given value.
	◦ ~Measurement: Does nothing (providing it avoids compiler warning).
	◦ toTimestamp (class method): Converts the given hour and minute values to the number of minutes since midnight. Throws a std::invalid_argument exception if one of the parameter values is out of its valid range.
	◦ toTimeOfDay (class method): Converts the given timestamp (minutes since midnight) to a string with the format “HH:MM”. The hours and minutes are represented with leading zeroes (e.g. “08:05”). (Reminder: Numbers can be converted to std::string with std::to_string.)
	◦ getTimestamp: Returns the timestamp value.
	◦ toString: Must be implemented by the derived classes.
	
b) Define class Temperature with its attribute temperature. The attribute holds a measured temperature (the time of measurement is stored by the base class). Declare and implement the following methods:
	◦ Temperature: “Forwards” the timestamp to the base class and Initialises the attribute with the given temperature value.
	◦ getTeperature: Returns the temperature value.
	◦ toString: Returns a string representing the value of the measurement as “Temperature: <temperature>°C” (see sample output below).

c) Test class Temperature by creating an instance measurement1 in main, representing a measured value of -3°C at 06:00 (use Measurement::toTimestamp to calculate the
timestamp). Output the result of toString on the console.

d) For a more comprehensive output, overload the left shift operator for ostream and Measurement (ostream& operator<<(ostream& lhs, Measurement& rhs))
(declare and implement in Measurement.h and Measurement.cpp respectively). The implementation writes to the output stream the timestamp (as “<HH:MM>”), a space and the
result from invoking the measurement’s toString method. Test your function in main.

e) Implement class Humidity in the same way as class Temperature. Method toString returns a string representing the value of the measurement as “Humidity: <humidity>%” (see sample output below).

f) Define the class MeasurementDb. It stores measurements from different locations. The data is stored in a map using the location as key and a vector of shared pointers to measurements as values. Declare and implement the following methods:
	◦ addMeasurement: Adds the given measurement to the database.
	◦ print: prints the content of the database.

g) Test class MeasurementDb in main by adding at least 3 measurements from two different locations using both types (temperature and humidity) and printing the content. Explain in a comment preceding your test statements why it would be a bad idea to use the previously defined measurement1 as one of the sample values.

Sample output:

```
Temperature: -3.000000°C
06:00 Temperature: -3.000000°C
Content of database:
Bath: 08:00 Humidity: 80.000000%
Kitchen: 10:05 Temperature: 20.000000°C
Kitchen: 12:00 Temperature: 22.000000°C
```


## Exercise 2 : Data Persistance

Persist the measurement database.
The format is defined as
	• A line with the location in square brackets, e.g. “[Kitchen]”
	• One or more Lines with measurements as timestamp (integer value), a semicolon as separator and the result from invoking toString on the measurement.
	• If more locations remain, a line with the next location in square brackets, and so on.

Sample output:

```
[Bath]
480;Humidity: 80.000000%
[Kitchen]
605;Temperature: 20.000000°C
720;Temperature: 22.000000°C
```

a) Implement method save of class MeasurementDb that writes the data as defined above to the ostream passed as argument. Test it by writing the data from the previous exercise to a file “data.txt”.

b) Implement the method parseLine of class Measurement. It takes a line with measurement data as written to the file and parses the beginning, i.e. the timestamp and the type (e.g. “Temperature” or “Humidity”). The remainder of the line is returned in the third parameter (e. g. “80.000000%”), because it cannot be interpreted by the base class. 

c) Add a class method fromString to both Temperature and Humidity. The method has as parameters a timestamp and a string representation of the value (it will be invoked with the remainder from parseLine in the next step). The implementations retrieve the value from the string representation and return a shared_ptr to a new instance of the respective derived class.

d) Implement method load of MeasurementDb. That’s how it works:
	1. Clear the database
	2. Try to read the next line from the file
	3. If no more lines are available, quit
	4. If the line represents a location, save its value and go back to step 2
	5. Use Measurement::parseLine to parse the line
	6. Depending on the type, invoke the respective class’s fromString
	7. Use the accumulated data to invoke addMeasurement
	8. Go back to step 2

e) Test your implementation by creating a second instance of MeasurementDb in main, loading the previously written file and printing the new database’s content.


## Exercise 3: Type conversion

Finally, implement a first “evaluation” function. In order to process the value of a measurement, it is necessary to cast a pointer to the base class (Measurement*) to a pointer to the actual class (Temperature* or Humidity*) else you cannot access its value. The casting can be done conveniently with the function dynamic_cast<DerivedType*>(pointerToBaseType)

The result of dynamic_cast is nullptr if the object pointed to is not of the desired type (as specified between the angle brackets), else it returns a pointer to the object with the desired type.

a) Implement class methods toType for both Temperature and Humidity. Each method returns nullptr if the argument does not point to an object of the method’s class, else it returns a pointer to the derived type. (If you have problems using dynamic_cast, simply return nullptr. This enables you to implement the remaining parts of the exercise – although you won’t get the expected result, of course.)

b) Implement the method maximumTemperature of class MeasurementDb. It searches the database for the maximum temperature measurement. If no measurement of type temperature exists, it returns false. Else a pointer to the measurement and the location where it was measured are returned as values of the parameters.
