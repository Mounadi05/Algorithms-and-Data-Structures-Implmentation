#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the length of a string 's' using recursion.
int ft_strlen(string s)
{
    if (s.size() == 0 ) return 0;
    return ft_strlen(s.substr(1)) + 1;
}

// Function to reverse a string 's' using recursion.
string ft_reverse(string s)
{    
    if (!s.size()) return "";
    return ft_reverse(s.substr(1)) + s[0];
}

// Function to reverse a string 's' using recursion.
string ft_reverseI(string s, int start = 0)
{    
    if (start == s.size()) return "";
    return ft_reverseI(s,++start) + s[start];
}

// Function to convert a decimal integer 'n' to binary representation using recursion.
string decimalToBinary(int n, string result = "")
{
    if (n <= 0) return result;
    result = to_string(n%2) + result;
    return decimalToBinary(n/2,result);
}

// Function to check if a string 's' is a palindrome using recursion.
bool palindrome(string s,int start = 0, int end = 0)
{
    if (start == 0) end = s.size()-1;
    if (start >= end) return true;
    if (s[start] == s[end])
        return palindrome(s,++start,--end);
    return false;

}

// Function to check if a string 's' is a palindrome using recursion.
bool palindromeI(string s)
{
    if (s.size() == 1 || s.size() == 0)
        return true;
    if (s[0] == s[s.size() -1])
        return palindromeI(s.substr(1,s.size()-2));
    return false;

}

// Function to calculate the sum of integers from 1 to 'n' using recursion.
int sumOfNumber(int n, int result = 0)
{    
    if (n == result) return result;
    return result + sumOfNumber(n, result+1);
}

// Function to calculate the sum of integers from 1 to 'n' using recursion.
int sumOfNumberI(int n )
{    
    if (n <= 1) return 1;
    return n + sumOfNumberI(n-1);
}

// Recursive function to perform binary search on a sorted vector of integers.
// Returns the index of the target if found, or -1 if not found.
int binarySearch(vector<int> &nums, int target,int left = 0, int right = -1)
{
    if (right == -1) right = nums.size() -1;
    if (left > right || nums[left] > target || nums[right] < target) 
        return -1;
    int mid = ((right + left)/2);
    if (nums[mid] == target) return mid;
    if (nums[mid] < target) 
        return binarySearch(nums,target,mid + 1,right);
    return binarySearch(nums,target,left,mid - 1); 
} 

// Recursive function to calculate the nth Fibonacci number.
// Returns the Fibonacci number at index 'n'.
int fib(int n)
{
    if (n == 0 || n == 1) return n;
    return fib(n - 1) + fib(n - 2);
} 

// Helper function for Merge Sort to merge two sorted subarrays into a single sorted array.
void merge(vector<int>& arr, int left, int middle, int right) 
{
    int L = middle - left + 1;
    int R = right - middle;
    int i = 0 , j = 0, k = left; 

    vector<int> leftArr(L);
    vector<int> rightArr(R);

    for (int i = 0; i < L; i++) leftArr[i] = arr[left + i];
    for (int i = 0; i < R; i++) rightArr[i] = arr[middle + 1 + i];
        

    while (i < L && j < R) 
        if (leftArr[i] <= rightArr[j]) arr[k++] = leftArr[i++];
        else arr[k++] = rightArr[j++];
    
    while (i < L) arr[k++] = leftArr[i++];
    
    while (j < R) arr[k++] = rightArr[j++];   
}

// Merge Sort function to sort an input vector of integers using the Merge Sort algorithm.
// - 'nums' is the vector to be sorted.
// - 'left' is the left index of the subarray to be sorted.
// - 'right' is the right index of the subarray to be sorted.
void mergeSort(vector<int> &nums, int left= 0, int right = -1)
{
    if (right == -1) right = nums.size() - 1;
    if (left < right)
    {
        int mid = (right + left)/2;
        mergeSort(nums,left, mid);
        mergeSort(nums,mid+1,right);
        merge(nums, left, mid, right);
    }
}

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to reverse a singly linked list using recursion.
// Returns the new head of the reversed list.
ListNode* reverseList(ListNode* head) 
{
    if (!head || !head->next) 
        return head;
    ListNode *tmp = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return tmp;
}

// Function to merge two sorted linked lists into a single sorted list.
// Returns the head of the merged list.
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
        if (!list1) return list2;
        if (!list2) return list1;
        if (list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1,list2->next);
            return list2;
        }
}

// Function to delete duplicate elements from a sorted linked list using recursion.
// Returns the head of the list after removing duplicates.
ListNode* deleteDuplicates(ListNode* head)
{
    if (!head)
        return head;
    if (head->next && head->val == head->next->val)
        return (deleteDuplicates(head->next));
    else
    {
        head->next =  deleteDuplicates(head->next);
        return (head);
    }
}
