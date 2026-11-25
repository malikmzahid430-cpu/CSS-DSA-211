#include<iostream>

using namespace std;


template <typename T>
class BST {
	template <typename U>    // if we take same type variable in nested scope it works in windows but it will not work in linex, so save side keep it diff.
	struct node {
		U Val;
		node <U> * left, * right, * parent;

	};
	node <T>* Head;

public:

	BST()
	{
		Head = new node<T>;
		Head->parent = Head;
		Head->left = Head;
		Head->right = Head;

	}
	void insert(const T &v)
	
	{
		if (Head->left = Head && Head->right = && Head->parent = Head) {

		
		node <T>* root;
		root = new node<T>;
		root->val = v;
		root->parent = Head;
		root->left = Head;
		root->right = Head;
		Head->parent = root;
		Head->left = root;
		Head->right = root;

		node<T>* ptr;
		ptr = root;
	}

		else {
			node <T>* temp;
			temp = new node<T>
				temp->val = v;
		}
		while (1)
		{
			if (temp->val < ptr->val) {
				if (ptr->left == Head) {

					ptr->left = temp;
					temp->left->right = Head;
					temp->parent = ptr;
					Head->left = temp;


				}
				else {
					ptr = ptr->left;
				}

			}
			else {

				if (root->right == Head) {


					root->right = temp;
					temp->left->right = Head;
					temp->parent = root;
					Head->right = temp;

				}
				else {

					ptr = ptr->right;
				}
			}
			
			



		}



	}


	bool find(const T v)
	{
		node<T>* ptr;

		ptr = Head->parent;
		while (ptr!=Head) {
			if (v == ptr->val)
				return 1;
			else {
				if (v < ptr->val) {
					ptr = ptr->parent->left;
				else {
					ptr = ptr->parent->right;

				}


				}

			}

		}
	}

	bool empty()
	{

		return (Head->left=Head && Head->right= && Head->parent = Head);

}



};

	