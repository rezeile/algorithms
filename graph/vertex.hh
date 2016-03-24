/*
 * Defines and implements a Vertex and 
 * Edge struct which represent a vertex
 * and an edge in a graph respectively.
 *
 * Implementation interface and details
 * heavily borrowed from basicgraph.h
 * implementation in Stanford's C++
 * library by Eric Roberts et al, which
 * can be found at the following address:
 * https://github.com/stepp/stanford-cpp-library/blob/master/StanfordCPPLib/basicgraph.h
 *
 * Author: Eliezer Abate
 * Date: March 23 2016 12:50 PST
 */

 /* Forward declarations of Vertex/Edge 
  * structures that have mutual dependence
  * on each other.*/
  
 struct Vertex;
 struct Edge;

 struct Vertex {
 public:
	std::string name;  // name of the vertex
	Set<Edge*> edges;  // outbound edges from this vertex

	/* supplementary data */
	double cost;    // cost to reach this vertex, useful in BST
	bool visited; 	// whether this vertex has been visited
	Vertex *pred; 	// vertex that comes before this vertex, NULL initially

	/*
	 * Constructs a vertex with the given name 
	 */
	 Vertex(const std::string& name = "");

	/*
	 * Copy constructor (rule of three).
	 */
	 Vertex(const Vertex& other);

    /* 
	 * Frees up any memory dynamically allocated by this vertex
	 */
	 ~Vertex();

	/*
	 * Returns the color of this vertex, if any. Initially WHITE.
	 */
	 int getColor() const;

	/* 
	 * Wipes the supplementary data of this vertex back to its 
	 * initial state. Specifically, sets cost to 0, visited to false,
	 * previous to NULL.
	 */
	 void resetData();

	/*
	 * Sets the color of this vertex to be the given color.
	 * The color must be on e of WHITE,GRAY, or BLACK.
	 * Future calls to getColor will return the color you pass
	 * here. 
	 */
	 void setColor(/* Color */ int c);

	/*
	 * Copy assignment operator (rule of three).
	 */
	Vertex& operator =(Vertex&& other);
 }
