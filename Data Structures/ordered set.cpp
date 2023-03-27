#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// can change to pair<int, int> also
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
/*
the way to create an ordered set is:
ordered_set <set_name>
functionalities:
<set_name>.insert(<element>);
<set_name>.find_by_order(k); == It returns to an iterator 
to the kth element (counting from zero) in the set in O(logn) time
<set_name>.order_of_key(k) == It returns to the number of items 
that are strictly smaller than our item k in O(logn) time.
*/
