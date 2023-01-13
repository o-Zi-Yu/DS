#ifndef priority_queue_h_
#define priority_queue_h_

#include <iostream>
#include <vector>
#include <cassert>


template <class T>
class priority_queue {
private:
  std::vector<T> m_heap;

public:
  priority_queue() {}

  priority_queue( std::vector<T> const& values )
  {
    for (int i = 0; i < values.size(); i++)
      push(values[i]);
  }

  const T& top() const 
  {
    assert( !m_heap.empty() );
    return m_heap[0]; 
  }

  void push( const T& entry )
  {
    m_heap.push_back(entry);
    int size = int parent = m_heap.size();
    while (parent){
      if (size < parent) {
        int parent = size / 2;
        swap(m_heap[size], m_heap[parent]); // value and other non-pointer member vars
        size = parent;
      }
      else
      break;
    }
  }

  void pop() 
  {
    assert( !m_heap.empty() );
    m_heap.pop_back();
    int size = m_heap.size();
    int current = 0;
    while (current < size) {
      if (m_heap[child] < m_heap[current]) {
        int child = size * 2;
        swap(m_heap[child], m_heap[parent]); // value and other non-pointer member vars
        size = child;
      }
      else
      break;
    }
  }

  int size() { return m_heap.size(); }
  bool empty() { return m_heap.empty(); }


  //  The following three functions are used for debugging.

  //  Check to see that internally the heap property is realized.
  bool check_heap( )
  {
    return this->check_heap( this->m_heap );
  }

  //  Check an external vector to see that the heap property is realized.
  bool check_heap( const std::vector<T>& heap )
  {percolate_up(TreeNode<T> * p) {
    while (p->parent)
    if (p->value < p->parent->value) {
    swap(p, parent); // value and other non-pointer member vars
    p = p->parent;
    }
    else
    break;
}

  }

  //  A utility to print the contents of the heap.  Use it for debugging.
  void print_heap( std::ostream & ostr )
  {
    for ( unsigned int i=0; i<m_heap.size(); ++i )
      ostr << i << ": " << m_heap[i] << std::endl;
  }
  
};


template <class T>
void heap_sort( std::vector<T> & v )
{
  if (v.size() == 0 || v.size() == 1) return;
  
  for (int i = v.size(); i >= 0; i++) {
    parent = i * 2;
    child = i;
    while (child < size) {
      if (v[child] < v[child + 1]){
        child += 1;
      }
      if (v[parent] < v[child]) {
        swap(v[parent], v[child]);
        parent = child;
        child = parent * 2;
      }
      else
      break;
    }
  }
}

#endif
