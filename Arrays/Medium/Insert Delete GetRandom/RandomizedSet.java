import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Random;

/*
Question :-
Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.
*/

public class RandomizedSet {

    // Hashmap and list.
    HashMap<Integer, Integer> map;
    List<Integer> temp;

    public RandomizedSet() {
        map = new HashMap<>();
        temp = new ArrayList<>();
    }

    public boolean insert(int val) {
        // if the values is already present in the map, then return false.
        if (map.containsKey(val) == true) {
            // value is present in the map, return false.
            return false;
        }

        // if the value is not present in the map, insert it and return true.
        temp.add(val);

        // store the value with it's index in map.
        int index = temp.size() - 1; // index of inserted value.
        map.put(val, index);// value stored in map.

        // value is successfully inserted in map, return true.
        return true;

    }

    public boolean remove(int val) {
        // if the values is not present in the map, then return false.
        if (map.containsKey(val) == false) {
            return false;
        }

        // value is present in the map.
        // if the values is present in the map, then delete the value and return true.

        // erase the val from map.
        // remove method in Hashmap take the key and return the value associated with key.
        // it deletes the key  from map also.
        int removedValueIdx = map.remove(val);
        
        // remove method in arraylist take the index and return the value at given index .
        // it deletes the value present at given index also.
        int lastIdx = temp.size() - 1;
        int lastValue = temp.remove(lastIdx);

        if (val != lastValue) {
            temp.set(removedValueIdx, lastValue);
            map.put(lastValue, removedValueIdx);
        }

        // value successfully deleted, return true.
        return true;

    }

    public int getRandom() {
        // initializing random class
        Random random_method = new Random();
        int idx = random_method.nextInt(temp.size());
        return temp.get(idx);
    }

}
