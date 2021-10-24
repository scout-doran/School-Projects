### Testing Exercise
Two airports are closeTo each other if they are within 25 miles of each other. Write the tests to show that the ``closeTo(Object o)`` method is not an ``equals`` method.

1.	Write the test to show that ``closeTo`` is reflexive (i.e., an airport a is closeTo itself)
2.	Write the test to show that ``closeTo``` is symmetric (i.e., an airport a is closeTo airport b then airport b is close to airport a)
3.	Write the test to show that ``closeTo`` is **not transitive** (i.e., airport a can be closeTo airport b and airport b can be closeTo airport c, but airport a is not closeTo airport c)

The setup code for each test is the following. You should use the ``closeTo`` method of the Airport
class to test the properties.

```text
ArrayList<Airport> list = db.findAirportByCity("Detroit");
// DTW
Airport ap0 = list.get(0);
// DET
Airport ap1 = list.get(1);
// YIP
Airport ap2 = list.get(2);
```

The three airports (DTW, DET, and YIP) have the following distances from each other:
* ``DTW – DET: 22 mi``
* ``DTW – YIP: 9 mi``
* ``DET – YIP: 29 mi``

Download the code from gitlab using:

```test
git clone https://gitlab.csc.tntech.edu/jgannod1/csc2310-sp21/lectures/airports.git
```

The test methods can be found in ``AirportDBTest.java`` as ``isReflective``, ``isSymmetric``, and ``isTransitive``.