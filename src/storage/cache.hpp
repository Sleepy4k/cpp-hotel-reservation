#pragma once

#ifndef STORAGE_CACHE_HPP
#define STORAGE_CACHE_HPP

#include <list>
#include <unordered_map>
#include <iostream>

using namespace std;

template <class K, class V>
class LRUCache {
private:
  // The maximum capacity of the cache
  size_t capacity;

  // A list of (key, value) pairs, where the most recently used item is at the front
  list<pair<K, V>> items;

  // A hash map that maps keys to iterators of the list
  unordered_map<K, typename list<pair<K, V>>::iterator> cache;

  // A helper function that moves an item to the front of the list
  void touch(typename list<pair<K, V>>::iterator it) {
    // Get the key and value of the item
    K key = it->first;
    V value = it->second;

    // Erase the item from its current position
    items.erase(it);

    // Insert the item at the front
    items.push_front(make_pair(key, value));

    // Update the iterator in the hash map
    cache[key] = items.begin();
  }

public:
  // Constructor that takes the capacity as an argument
  LRUCache(size_t capacity): capacity(capacity) {}

  // A function that returns the value associated with a key
  V get(K key) {
    // If the key is not in the cache, return -1 (or any other default value)
    if (cache.find(key) == cache.end()) {
      return "-1";
    }

    // Get the iterator of the item from the hash map
    auto it = cache[key];

    // Move the item to the front of the list
    touch(it);

    // Return the value of the item
    return it->second;
  }

  // A function that inserts or updates a key-value pair in the cache
  void put(K key, V value) {
    // If the key is already in the cache, update its value and move it to the front of the list
    if (cache.find(key) != cache.end()) {
      auto it = cache[key];
      it->second = value;
      touch(it);
      return;
    }

    // If the cache is full, remove the least recently used item from both the list and the hash map
    if (items.size() == capacity) {
      K lru_key = items.back().first;
      items.pop_back();
      cache.erase(lru_key);
    }

    // Insert a new item at the front of the list
    items.push_front(make_pair(key, value));

    // Add a new entry to the hash map
    cache[key] = items.begin();
  }

  // A function that prints all the items in the cache for debugging purposes
  void print() {
    for (auto& p : items) {
      cout << p.first << " : " << p.second << endl;
    }
  }
};

#endif // STORAGE_CACHE_HPP