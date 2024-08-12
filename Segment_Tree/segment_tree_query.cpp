#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node {

	ll value;
	struct Node *L, *R;
};

struct Node* getnode()
{
	struct Node* temp = new struct Node;
	temp->value = 0;
	temp->L = NULL;
	temp->R = NULL;
	return temp;
}

struct Node* root;
void UpdateHelper(struct Node* curr, ll index,
				ll L, ll R, ll val)
{

	if (L > index || R < index)
		return;

	if (L == R && L == index) {
		curr->value = val;
		return;
	}
	ll mid = L - (L - R) / 2;
	ll sum1 = 0, sum2 = 0;

	if (index <= mid) {

		if (curr->L == NULL)
			curr->L = getnode();

		UpdateHelper(curr->L, index, L, mid, val);
	}

	else {

		if (curr->R == NULL)
			curr->R = getnode();
		UpdateHelper(curr->R, index, mid + 1, R, val);
	}

	if (curr->L)
		sum1 = curr->L->value;
	if (curr->R)
		sum2 = curr->R->value;
	curr->value = sum1 + sum2;
	return;
}

ll queryHelper(struct Node* curr, ll a,
			ll b, ll L, ll R)
{

	if (curr == NULL)
		return 0;
	if (L > b || R < a)
		return 0;

	if (L >= a && R <= b)
		return curr->value;

	ll mid = L - (L - R) / 2;

	return queryHelper(curr->L, a, b, L, mid)
		+ queryHelper(curr->R, a, b, mid + 1, R);
}

ll query(int L, int R)
{
	ll lo 
	= 1;
	ll hi = n; //n is size()
	return queryHelper(root, L, R, 1, 10);
}

void update(int index, int value)
{
	ll lo = 1;
	ll hi = n;//update the range here n is size here also
	UpdateHelper(root, index, lo, hi, value);
}


// query(a,b)-> gives value in range (a,b)
// update(a,b)-> updates value
// also see the values passed in queryHelper() and UpdateHelper()

int main()
{

	return 0;
}
