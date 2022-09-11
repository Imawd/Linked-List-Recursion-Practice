#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{ 
	if (tail_ == NULL)
  {
    tail_ = new Item();
    tail_->last = 1;
    tail_->first = 0;
    tail_->val[tail_->first] = val;
    head_ = tail_;
    size_++;
  }

  else
  {

    if (tail_->last != ARRSIZE)
    {
      tail_->val[tail_->last] = val;
      tail_->last += 1;
      size_++;
    }

    else 
    {
			Item* temp = new Item(); //not actually a temp, rather a new node, not to be dealloc'd
			temp->val[0] = val;
      temp->first = 0;
			temp->last = 1;
			temp->prev = tail_;
			tail_->next = temp;
			tail_ = temp;
      size_++;
    }
    
  }

	

}

void ULListStr::pop_back()
{

  if (tail_ == NULL) return;

  else
  {
    tail_->last -= 1;
		size_ -= 1;

    if (tail_->last - tail_->first == 0)
    {
        Item* temp = tail_;
        tail_ = temp->prev;
        if (tail_ != NULL) tail_->next = NULL;
    		else head_ = NULL;

        delete temp;
      
    }

      
  }


}

void ULListStr::push_front(const std::string& val)
{
	
  if (head_ == NULL)
  {
    head_ = new Item();
    size_++;
		head_->val[ARRSIZE-1] = val;
		head_->first = ARRSIZE-1;
    head_->last = ARRSIZE;
    tail_ = head_;
  }

  else 
  {
    if (head_->first != 0)
    {
      head_->first -= 1;
      head_->val[head_->first] = val;
      size_++;
    }
    else
    {
			Item* temp = new Item(); //not actually a temp, a new node and shouldn't be deallocated
			temp->val[ARRSIZE - 1] = val;
			temp->last = ARRSIZE;
			temp->first = ARRSIZE-1;
			temp->next = head_;
			head_->prev = temp;
			head_ = temp;
			size_++;
    }

  }	
		
}

void ULListStr::pop_front() 
{
  if (head_ == NULL) return;

  else if (head_ != NULL)
  {
    size_--;
    head_->first += 1;

    if (head_->last - head_->first == 0)
    {
      
      Item* temp = head_;
      head_ = temp->next;
      if (head_ != NULL) head_->prev = NULL;
    	else tail_ = NULL;
      
			delete temp;

    }

  }


}

std::string const & ULListStr::back() const 
{
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{

  if (head_ == nullptr) return NULL;

  else if (loc > size_) return NULL;

  else
  {
    Item* temp = head_;

    while (loc >= 0)
    {
      
      if ((temp->last - temp->first) >= loc)
      {     
        return &temp->val[temp->first + loc];
      }      
      
      loc -= (temp->last - temp->first);
      temp = temp->next;

    }
    delete temp;
  }

  return NULL;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
