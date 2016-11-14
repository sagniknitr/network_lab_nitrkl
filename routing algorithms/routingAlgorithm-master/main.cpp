#include "graph.cpp"

using namespace std;
/* Read message from istream, could be std::cin or ifstream 
 * Input Format: <source> <destination> <message>
 * Output Format: From <source> to <destination> hops <hop> ... <hop> <message content>
 */
void readMessage(ostream& out, istream& in, Graph& graph){
 	while(in.good()){
 		int from, to;
 		char msg[256];
 		in >>from;
 		if(from == -1) break;
 		in >>to >>msg[0]; //the last one is to get rid of heading spaces.
 		in.getline(msg+1, 256);
 		graph.sendMsg(from, to, msg, out);
 	}
}

/* Using std io. */
void run(ostream& out, istream& in, int choice){
	Graph graph;
	/* Read topology from file */
    out << "Please input graph topology, <vertice 1> <vectice 2> <dist> : \n";
    out <<"Enter -1 to finish this section.\n";
    int src, dest, cost;
    while(true){
    	in >> src;
    	if(src == -1) break;
    	in >> dest >> cost;
    	graph.addVertice(src);
    	graph.addVertice(dest);
    	graph.addOrUpdateEdge(src, dest, cost);
    	graph.addOrUpdateEdge(dest, src, cost);
    }
    graph.printGraph(out);
    if(choice == 1)
    	graph.runLinkState();
    else
    	graph.runDistVectAlgor();
    graph.printAllRoutingTables(out);

    /** Start exchange messages **/
 	out <<"Please input message to sent, input Format: <source> <destination> <message>.\n";
 	out <<"Enter -1 to finish this section.\n";
 	readMessage(out, in, graph);

 	/** Topology will change now **/
 	while(true){
 		out <<"Please input the changes happen to the graph.\n";
	 	out <<"With format: <vertice 1> <vectice 2> <dist>\n";
	 	out <<"Negative distance means deleting the existing edge\n";
	 	out <<"Enter -1 to finish this section.\n";
 		int src, dest, cost;
 		in >> src;
 		if(src == -1) break;
 		in >> dest >> cost;
 		graph.addOrUpdateEdge(src, dest, cost);
 		graph.addOrUpdateEdge(dest, src, cost);
 		graph.printGraph(out);
 		if(choice == 1)
    		graph.runLinkState();
    	else
    		graph.runDistVectAlgor();
    	graph.printAllRoutingTables(out);

    	/** Start exchange messages **/
	 	out <<"Please input message to sent, input Format: <source> <destination> <message>.\n";
	 	out << "Enter a single -1 when you are finished with message sending: \n";
	 	readMessage(out, in, graph);
 	}
}
/* Using file io. */
void run(ostream& out, char* argv[], int choice)
{
	Graph graph;
	/* Read topology from file */
	std::ifstream instr;
    instr.open(argv[1]);
    int src, dest, cost;
    while(instr.good()){
    	instr >> src >> dest >> cost;
    	graph.addVertice(src);
    	graph.addVertice(dest);
    	graph.addOrUpdateEdge(src, dest, cost);
    	graph.addOrUpdateEdge(dest, src, cost);
    }
    instr.close();
    graph.printGraph(out);
    if(choice == 1)
    	graph.runLinkState();
    else
    	graph.runDistVectAlgor();
    graph.printAllRoutingTables(out);

    /** Start exchange messages **/
 	ifstream imsgstr;
 	imsgstr.open(argv[2]);
 	readMessage(out, imsgstr, graph);
 	imsgstr.close();

 	/** Topology will change now **/
 	ifstream ichange;
 	ichange.open(argv[3]);
 	while(ichange.good()){
 		int src, dest, cost;
 		ichange >> src >> dest >> cost;
 		graph.addOrUpdateEdge(src, dest, cost);
 		graph.addOrUpdateEdge(dest, src, cost);
 		graph.printGraph(out);
 		if(choice == 1)
	    	graph.runLinkState();
	    else
	    	graph.runDistVectAlgor();
    	graph.printAllRoutingTables(out);

    	/** Start exchange messages **/
    	ifstream imsgstr;
	 	imsgstr.open(argv[2]);
	 	readMessage(out, imsgstr, graph);
	 	imsgstr.close();
 	}
 	ichange.close();
 	if(choice == 1)
 		std::cout<<"Output to linkstate_output.txt.\n";
 	else
 		std::cout<<"Output to distvec_output.txt.\n";
}

int main(int argc, char* argv[]){
	if(!(argc == 2 && strcmp(argv[1],"stdio") == 0) && argc != 4){
		printf("Usage: ./routingAlgor stdio or ./routingAlgor <topofile> <messagefile> <changesfile>.\n");
		exit(0);
	}
	
	std::cout<<"Input 1 for Linkstate, 2 for Distance Vector: ";
	int choice = 0;
	while(choice != 1 && choice != 2){
		std::cin>>choice;
	}

	if(argc == 4){
		ofstream out;
		if(choice == 1)
			out.open("linkstate_output.txt");
		else
			out.open("distvec_output.txt");
		ifstream in;
		run(out, argv,choice);
		out.close();
	}
	else{
		run(std::cout, std::cin, choice);
	}

    return 0;
}


