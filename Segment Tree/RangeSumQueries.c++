// YOU'RE GIVEN A ARRAY [0...n - 1].
// YOU HAVE TO PERFORM TWO QUERIES :
// #1 Find the sum of the elements in the range [l, r], where 0 <= l <= r <= n - 1.
// #2 Change the value of a specified element of the array to a new value 'val'.

#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
	vector<int> segment;

public:
	SegmentTree(int n)
	{
		segment.resize(2 * n - 1);
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

	int query(int ind, int low, int high, int l, int r)
	{
		// IF THE GIVEN RANGE HAS NO OVERLAP WITH THE NODE RANGE, SIMPLY RETURN:
		// [l...r...low...high] OR [low...high...l...r]
		if (r < low || high < l)
		{
			return 0;
		}

		// IF THE GIVEN RANGE PERFECTLY LIES INSIDE THE NODE RANGE, RETURN THE INDEX VALUE:
		// [l...low...high...r]
		else if (l <= low && high <= r)
		{
			return segment[ind];
		}

		// ELSE THERE IS A PARTIAL OVERLAP OF THE GIVEN RANGE AND THE NODE RANGE, THEN MOVE TO THE
		// LEFT AND RIGHT OF THE THAT PARTICULAR NODE AND RETURN THEIR SUM :
		int mid = low + (high - low) / 2;
		return query(2 * ind + 1, low, mid, l, r) + query(2 * ind + 2, mid + 1, high, l, r);
	}

	void update(int ind, int low, int high, int i, int val)
	{
		// IF REACHED THE ith INDEX NODE, UPDATE THE NODE VALUE AND RETURN:
		if (low == high)
		{
			segment[ind] = val;
			return;
		}
		int mid = low + (high - low) / 2;

		// IF i LIES ON THE LEFT CHILD NODE OF THE SEGMENT TREE, MOVE LEFT :
		if (i <= mid)
		{
			update(2 * ind + 1, low, mid, i, val);
		}

		// IF i LIES ON THE RIGHT CHILD NODE OF THE SEGMENT TREE, MOVE RIGHT :
		else
		{
			update(2 * ind + 2, mid + 1, high, i, val);
		}

		// UPDATE EVERY NODE TO THE SUMMATION OF THEIR CHILDREN NODES :
		segment[ind] = segment[2 * ind + 1] + segment[2 * ind + 2];
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
		// TYPE 'I' QUERY : QUERY FOR SUMMATION OF NUMBER IN THE GIVEN RANGE !
		// TYPE 'II' QUERY : QUERY FOR UPDATION IN THE INPUT ARRAY !

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
			int val, i;
			cin >> i >> val;
			st.update(0, 0, n - 1, i, val);
			arr[i] = val;
		}
	}

	return 0;
}
