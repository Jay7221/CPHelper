#include<bits/stdc++.h>
using namespace std;
int MAX = 1e9;


// --------------------------------------- Random Generation Function ----------------------------------


template<typename T>
int randNum(T mn, T mx)
{
	if(mx < mn)
	{
		throw exception();
	}
	int diff = mx - mn + 1;
	T n = std::rand() % diff;
	n = mn + n;
	return n;
}
template<typename T>
std::vector<T> randArray(int n, T mx, T mn)
{
	std::vector<T> arr(n);
	for(int i = 0; i < n; ++i)
	{
		arr[i] = randNum(mn, mx);
	}
	return arr;
}
template<class T>
void shuffle(std::vector<T> &arr)
{
	std::random_shuffle(arr.begin(), arr.end());
}
template<class T> 
void shuffle(T start, T end)
{
	std::random_shuffle(start, end);
}
template<class T>
void debug(T &arr)
{
	for(auto elem : arr)
	{
		std::cerr << elem << ' ';
	}
	std::cerr << '\n';
}


// ------------------------------------End of Random Generation Function -------------------------------

// ------------------------------------------ Class Definitions ----------------------------------------
class Array
{
	private:
		int N;
		vector<int> arr;
		int MAX, MIN;
	public:
		// Initiaialize an array of size n
		Array(int n);
		// set the min max possible values to mn and mx
		void setMinMax(int mn, int mx);
		// generate an array with sum of elements equal to sum
		void generateArrayWithSum(int sum);
		// generate a random array
		void generate();
		// get the array
		vector<int> getArray();
		// print array
		void print();
		// print array in the way it is done in contests
		// size_of_array
		// arr0 arr1 ... arrN-1
		void printStandard();
};


class Graph
{
	private:
		int numNodes;
		int numEdges;
		int nodeLimit;
		int minWeight, maxWeight;
		vector<vector<int>> edges;
		vector<vector<int>> weightedEdges;
		// clear the set of edges
		void clearEdges();
	public:
		Graph();
		Graph(int n, int m);
		// Set the minimum possble weight to mn and maximum possible weight possible to mx
		void setWeight(int mn, int mx);
		// generate an Undirected graph
		void generateUndirected();
		// generate an Directed graph
		void generateDirected();
		// generate Directed Acyclic Graph where it is possible to go from node 1 to node N
		void generateConnectedDirectedAcyclic();
		// Assign weights to each edge of graph
		void weightGraph();
		
		vector<vector<int>> getGraph();
		vector<vector<int>> getWeightedGraph();
		int getNumNodes();
		int getNumEdges();
		// Print unweighted graph
		void print();
		// Print the weighted graph
		void printWeighted();
		// Print unweighted graph in standard CP form
		// n m
		// m lines of form -> u v
		void printStandard();
		// Print Weighted graph in standard CP form
		// n m
		// m lines of form -> u v w
		void printStandardWeighted();
};

class TestCaseGenerator
{
	public:
		// Initializes an empty testcase generator
		TestCaseGenerator();
		// Initialzes an testcase generator with minimum mn testcases and maximum mx testcases
		TestCaseGenerator(int mn, int mx);
};

// -------------------------------------- End of Class Definitions -------------------------------------

// ------------------------------------------ Method Definitions ----------------------------------------

// ----------------------- Methods of Array Class -----------------------------------------------------
Array::Array(int n)
{
	N = n;
	arr.assign(N, 0);
	MAX = 1e9;
	MIN = 1;
}
void Array::setMinMax(int mn, int mx)
{
	MIN = mn;
	MAX = mx;
}
void Array::generateArrayWithSum(int sum)
{
	assert(N * MIN <= sum);
	sum -= N * MIN;
	for(int i = 0; i < N; ++i)
	{
		arr[i] = randNum(0, sum);
	}
	sort(arr.begin(), arr.end());
	arr[N - 1] = sum;
	for(int i = N - 1; i > -1; --i)
	{
		arr[i] = arr[i] - arr[i - 1];
	}
	for(int i = 0; i < N; ++i)
	{
		arr[i] += MIN;
	}

	shuffle(arr);
}
void Array::generate()
{
	for(int i = 0; i < N; ++i)
	{
		arr[i] = randNum(MIN, MAX);
	}
}
vector<int> Array::getArray()
{
	return arr;
}
void Array::print()
{
	for(int i = 0; i < N; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
}
void Array::printStandard()
{
	cout << N << '\n';
	print();
}
// ----------------------- End of Methods of Array Class ------------------------------------------------



// ----------------------- Methods of Graph Class -----------------------------------------------------
Graph::Graph()
{
	numNodes = 0;
	numEdges = 0;
	minWeight = 1;
	maxWeight = 1e9;
}
Graph::Graph(int n, int m)
{
	numNodes = n;
	numEdges = m;
	minWeight = 1;
	maxWeight = 1e9;
}
void Graph::setWeight(int mn, int mx)
{
	minWeight = mn;
	maxWeight = mx;
}
void Graph::clearEdges()
{
	edges.clear();
	weightedEdges.clear();
}
void Graph::generateUndirected()
{
	clearEdges();
	if(numNodes < nodeLimit)
	{
		for(int u = 1; u <= numNodes; ++u)
		{
			for(int v = u + 1; v <= numNodes; ++v)
			{
				edges.push_back({u, v});
			}
		}
		shuffle(edges);
		while(edges.size() > numEdges)
		{
			edges.pop_back();
		}
	}
	else
	{
		map<int, bool> vis;
		while(edges.size() < numEdges)
		{
			int u = randNum(1, numNodes);
			int v = randNum(1, numNodes);
			int x = u * (numNodes + 1) + v, y = v * (numNodes + 1) + u;
			if((u != v) && (!vis[x]) && (!vis[y]))
			{
				vis[x] = vis[y] = true;
				edges.push_back({u, v});
			}
		}
	}
}
void Graph::generateDirected()
{
	clearEdges();
	if(numNodes < nodeLimit)
	{
		for(int u = 1; u <= numNodes; ++u)
		{
			for(int v = 1; v <= numNodes; ++v)
			{
				if(u != v)
				{
					edges.push_back({u, v});
				}
			}
		}
		shuffle(edges);
		while(edges.size() > numEdges)
		{
			edges.pop_back();
		}
	}
	else
	{
		map<int, bool> vis;
		while(edges.size() < numEdges)
		{
			int u = randNum(1, numNodes);
			int v = randNum(1, numNodes);
			int x = u * (numNodes + 1) + v;
			if((u != v) && (!vis[x]))
			{
				vis[x] = true;
				edges.push_back({u, v});
			}
		}
	}
}
void Graph::generateConnectedDirectedAcyclic()
{
	clearEdges();
	assert(numEdges >= numNodes - 1);
	vector<int> nodes(numNodes + 1);
	for(int i = 1; i <= numNodes; ++i)
	{
		nodes[i] = i;
	}
	shuffle(nodes.begin() + 1, nodes.end() - 1);
	int k = 1;
	for(int k = 1; (k < numNodes) && (edges.size() < numEdges); ++k)
	{
		for(int i = k + 1; (i <= numNodes) && (edges.size() < numEdges); ++i)
		{
			edges.push_back({nodes[i - k], nodes[i]});
		}
	}
	assert(edges.size() == numEdges);
}
void Graph::weightGraph()
{
	weightedEdges.clear();
	for(auto edge : edges)
	{
		int w = randNum(minWeight, maxWeight);
		weightedEdges.push_back({edge[0], edge[1], w});
	}
}


vector<vector<int>> Graph::getGraph()
{
	return edges;
}
vector<vector<int>> Graph::getWeightedGraph()
{
	return weightedEdges;
}
int Graph::getNumNodes()
{
	return numNodes;
}
int Graph::getNumEdges()
{
	return numEdges;
}
void Graph::print()
{
	for(auto edge : edges)
	{
		cout << edge[0] << ' ' << edge[1] << '\n';
	}
}
void Graph::printWeighted()
{
	for(auto edge : weightedEdges)
	{
		assert(edge[0] <= numNodes);
		assert(edge[1] <= numEdges);
		assert(edge[2] <= maxWeight);
		cout << edge[0] << ' ' << edge[1] << ' ' << edge[2] << '\n';
	}
}
void Graph::printStandard()
{
	cout << numNodes << ' ' << numEdges << '\n';
	print();
}
void Graph::printStandardWeighted()
{
	cout << numNodes << ' ' << numEdges << '\n';
	printWeighted();
}
// ----------------------- End of Methods of Graph Class ------------------------------------------------

// -------------------------------------- End of Method Definitions -------------------------------------








void generateTestCase()
{

}
int main()
{
	srand(time(0));
	return 0;	
}