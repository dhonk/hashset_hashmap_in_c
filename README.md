# Hashset and Hashmap in C!

### Watch me code the whole thing here -> [YouTube](https://youtu.be/g8FT3K14Zow)

## Hashset
Implement a Hashset 

Python:
- void add(key) Inserts the value key into the HashSet.
- bool contains(key) Returns whether the value key exists in the HashSet or not.
- void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.


### Example:

    MyHashSet myHashSet = new MyHashSet();  
    myHashSet.add(1);      // set = \[1\]  
    myHashSet.add(2);      // set = \[1, 2\]  
    myHashSet.contains(1); // return True  
    myHashSet.contains(3); // return False, (not found)  
    myHashSet.add(2);      // set = \[1, 2\]  
    myHashSet.contains(2); // return True  
    myHashSet.remove(2);   // set = \[1\]  
    myHashSet.contains(2); // return False, (already removed)  

### Constraints
0 <= key <= 106  
At most 104 calls will be made to add, remove, and contains.

## Hashmap
Implement a Hashmap

Python:
- MyHashMap() initializes the object with an empty map.
- void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
- int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
- void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.

### Example

    MyHashMap myHashMap = new MyHashMap();
    myHashMap.put(1, 1); // The map is now \[\[1,1]]
    myHashMap.put(2, 2); // The map is now \[\[1,1], \[2,2]]
    myHashMap.get(1);    // return 1, The map is now \[\[1,1], \[2,2]]
    myHashMap.get(3);    // return -1 (i.e., not found), The map is now \[\[1,1], \[2,2]]
    myHashMap.put(2, 1); // The map is now \[\[1,1], \[2,1]] (i.e., update the existing value)
    myHashMap.get(2);    // return 1, The map is now \[\[1,1], \[2,1]\]
    myHashMap.remove(2); // remove the mapping for 2, The map is now \[\[1,1]]
    myHashMap.get(2);    // return -1 (i.e., not found), The map is now \[\[1,1]]

### Constraints
0 <= key, value <= 106  
At most 104 calls will be made to put, get, and remove.