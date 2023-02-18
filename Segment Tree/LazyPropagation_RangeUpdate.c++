// IF THERE IS A UPDATE IN A RANGE, THEN WE CAN MAKE A updateRange() THAT UPDATE SEGMENT TREE FOR EACH VALUE IN THE RANGE.
// BUT THIS CAN TAKE A BIT HIGHER TIME TO GET EXECUTED.
// A BETTER APPROACH CAN BE, WHEN THERE ARE MANY UPDATES AND UPDATES ARE DONE ON A RANGE, WE CAN POSTPONE SOME UPDATES
// (AVOID RECURSIVE CALLS IN UPDATE) AND DO THOSE UPDATES ONLY WHEN REQUIRED.
// WE WILL CREATE A LAZY ARRAY TO STORE THE LAZY NODE VALUES, THIS LAZY ARRAY WILL STORE EVERY NODE'S LAZY VALUE SO THE
// SIZE OF THE LAZY ARRAY WILL BE SAME AS OF THE SEGMENT TREE ARRAY.
// INTIALLY ALL NODE HAVE NO PENDING UPDATE, THEREFORE ALL VALUE WILL BE INTIALIZED WITH 0.
// ANY NON - ZERO VALUE OF LAZY[] MEANS THAT THIS AMOUNT NEEDS TO BE ADDED TO THE CORRESPONDING NODE IN THE SEGMENT TREE
// ARRAY BEFORE MAKING ANY QUERY TO THAT NODE.

#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
	// CREATING TWO VECTORS, SEGMENT FOR STORING SEGMENT TREE AND LAZY FOR STORING PENDING UPDATE VALUE:
	vector<int> segment, lazy;

public:
	SegmentTree(int n)
	{
		// SIZE OF BOTH SEGMENT AND LAZY VECTOR WILL BE EQUAL :
		segment.resize(4 * n);
		lazy.resize(4 * n);
	}

	void build(int ind, int low, int high, int arr[])
	{
		// IF REACHING THE LEAF NODE I.E; THE RANGE BECOMES [low - low] or [high - high] SET THE SEGMENT TREE AS SAME
		// VALUE AS ON arr[low] or arr[high] :
		if (low == high)
		{
			segment[ind] = arr[low];
			return;
		}
		// BREAKING THE RANGE INTO TWO EQUAL HALVES :
		int mid = low + (high - low) / 2;

		// RANGING FROM [low - mid] :
		build(2 * ind + 1, low, mid, arr);

		// AND FROM [mid + 1 - high] :
		build(2 * ind + 2, mid + 1, high, arr);

		// INTIALIZE THE NODES AS SUMMATION OF ITS CHILD NODES :
		segment[ind] = segment[2 * ind + 1] + segment[2 * ind + 2];
	}

	void update(int ind, int low, int high, int l, int r, int val)
	{
		// IF THERE IS A PENDING UPDATE, DO UPDATE FIRST BEFORE ANY UPDATION:
		if (lazy[ind] != 0)
		{

			// ADD THE PENDING UPDATE VALUES IN THE LAZY ARRAY TIMES NUMBER OF CHILDREN OF THAT NODE :
			segment[ind] += (high - low + 1) * lazy[ind];

			// IF THERE EXISTS CHILDREN OF THAT NODE:
			if (low != high)
			{
				// UPDATE THE LEFT CHILD BY ADDING THE LAZY INDEX VALUE OF THE NODE:
				lazy[2 * ind + 1] += lazy[ind];

				// UPDATE THE RIGHT CHILD BY ADDING THE LAZY INDEX VALUE OF THE NODE:
				lazy[2 * ind + 2] += lazy[ind];
			}

			// MAKE THE LAZY INDEX OF THAT NODE TO BE ZERO AFTER THE UPDATION :
			lazy[ind] = 0;
		}

		// IF THERE IS NO OVERLAP, SIMPLY RETURN :
		if (high < l || r < low)
			return;

		// IF THERE IS A COMPLETE OVERLAP :
		else if (l <= low && high <= r)
		{
			// ADD THE VALUE TO BE ADDED BY NUMBER OF CHILDREN TIMES :
			segment[ind] += (high - low + 1) * val;

			// IF THERE EXISTS THE CHILDREN :
			if (low != high)
			{

				// ADD THE VALUE TO BE ADDED TO ITS PENDING UPDATE LAZY ARRAY OF BOTH THE CHILDREN:
				lazy[2 * ind + 1] += val;
				lazy[2 * ind + 2] += val;
			}

			// AND RETURN :
			return;
		}

		// ELSE IF THERE IS A PARTIAL OVERLAP GO TO THE LEFT AND THE RIGHT CHILDREN:
		int mid = low + (high - low) / 2;
		update(2 * ind + 1, low, mid, l, r, val);
		update(2 * ind + 2, mid + 1, high, l, r, val);

		// ANY SEGMENT NODE HAS THE VALUE OF SUMMATION OF ITS CHILDREN :
		segment[ind] = segment[2 * ind + 1] + segment[2 * ind + 2];
	}

	int query(int ind, int low, int high, int l, int r)
	{
		// IF THERE IS A PENDING UPDATE, DO UPDATE FIRST BEFORE ANY UPDATION:
		if (lazy[ind] != 0)
		{

			// ADD THE PENDING UPDATE VALUES IN THE LAZY ARRAY TIMES NUMBER OF CHILDREN OF THAT NODE :
			segment[ind] += (high - low + 1) * lazy[ind];

			// IF THERE EXISTS CHILDREN OF THAT NODE:
			if (low != high)
			{
				// UPDATE THE LEFT CHILD BY ADDING THE LAZY INDEX VALUE OF THE NODE:
				lazy[2 * ind + 1] += lazy[ind];

				// UPDATE THE RIGHT CHILD BY ADDING THE LAZY INDEX VALUE OF THE NODE:
				lazy[2 * ind + 2] += lazy[ind];
			}

			// MAKE THE LAZY INDEX OF THAT NODE TO BE ZERO AFTER THE UPDATION :
			lazy[ind] = 0;
		}

		// IF THERE IS NO OVERLAP RETURN 0 :
		if (high < l || r < low)
			return 0;

		// IF THERE IS A COMPLETE OVERLAP RETURN THAT PARTICUALT INDEX NODE :
		else if (l <= low && high <= r)
			return segment[ind];

		// ELSE IF THERE IS A PARTIAL OVERLAP, GO TO ITS LEFT AND RIGHT CHILDREN :
		int mid = low + (high - low) / 2;
		return query(2 * ind + 1, low, mid, l, r) + query(2 * ind + 2, mid + 1, high, l, r);
	}
};

int main(void)
{
	// TAKING INPUT:
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	// CREATING A OBJECT I.E; A SEGMENT TREE:
	SegmentTree st(n);

	// BUILDING THE SEGMENT TREE FOR THE GIVEN INPUT:
	st.build(0, 0, n - 1, arr);

	// TAKING QUERIES' INPUT :
	int q;
	cin >> q;
	while (q--)
	{
		// TYPE 'I' QUERY : QUERY FOR MINIMUM OF NUMBER IN THE GIVEN RANGE !
		// TYPE 'II' QUERY : QUERY FOR RANGE UPDATION IN THE INPUT ARRAY !

		// TAKING INPUT FOR TYPE OF QUERY :
		int type;
		cin >> type;

		// TAKING INPUT OF THE RANGE :
		if (type == 1)
		{
			int l, r;
			cin >> l >> r;
			cout << st.query(0, 0, n - 1, l, r) << "\n";
		}
		else
		{
			int l, r, val;
			cin >> l >> r >> val;
			st.update(0, 0, n - 1, l, r, val);
		}
	}

	return 0;
}
