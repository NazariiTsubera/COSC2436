
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>


class Graph {
private:
    size_t nodes;
    std::vector<std::vector<bool>> graph;
public:
    Graph(size_t nodes) : nodes(nodes), graph(nodes) {
        for (auto& column : graph) {
            column.resize(nodes);
        }
    }


public:
    bool isEdge(size_t x, size_t y) const {
        return graph[x][y];
    }

    void setEdge(size_t x, size_t y, bool value) {
        graph[x][y] = value;
    }

    [[nodiscard]] size_t getEdges() const {
        size_t edges = 0;

        for (auto& column : graph) {
            for (auto row : column) {
                if (row) {
                    edges++;
                }
            }
        }

        return edges;
    }

    [[nodiscard]] size_t getNodes() const {
        return nodes;
    }




    /**
     * Assumes this structure
     *
     * 1st line - one number, that represents a number of vertices in this graph
     * other lines are pairs X Y - represent an existence of specific edge between X and Y nodes
     * @param filename
     * @return Graph
     */
    static Graph buildFromFile(std::string filename) {
        std::ifstream file(filename);

        if (!file.is_open()) {
            throw std::runtime_error("Could not open file");
        }


        //get number of nodes
        std::string line;
        std::getline(file, line);

        size_t nodes = std::stoul(line);

        Graph graph(nodes);

        while (std::getline(file, line)) {
            std::stringstream ss(line);
            size_t x, y;
            ss >> x >> y;
            graph.setEdge(x, y, true);
        }

        return graph;
    }
};

std::string findDataFile(const std::string& filename) {
    std::vector<std::string> paths = {
        "Assignment13/data/" + filename,
        "data/" + filename,
        "../data/" + filename,
    };

    for (const std::string& path : paths) {
        std::ifstream file(path);

        if (file.is_open()) {
            return path;
        }
    }

    throw std::runtime_error("Could not find data file: " + filename);
}

void printGraph(const Graph& graph) {
    std::cout << "Vertices: " << graph.getNodes() << '\n';
    std::cout << "Edges: " << graph.getEdges() << "\n\n";
    std::cout << "Adjacency matrix:\n";

    for (size_t x = 0; x < graph.getNodes(); x++) {
        for (size_t y = 0; y < graph.getNodes(); y++) {
            std::cout << graph.isEdge(x, y) << ' ';
        }

        std::cout << '\n';
    }
}

void runExample(const std::string& filename) {
    std::string path = findDataFile(filename);
    Graph graph = Graph::buildFromFile(path);

    std::cout << "\nLoaded " << path << "\n\n";
    printGraph(graph);
    std::cout << '\n';
}

void printMenu() {
    std::cout << "Graph examples\n";
    std::cout << "1. Simple directed graph\n";
    std::cout << "2. Undirected square\n";
    std::cout << "3. Disconnected components\n";
    std::cout << "4. Cycles and self-loop\n";
    std::cout << "5. Dense directed graph\n";
    std::cout << "6. Isolated vertices\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose an example: ";
}


int main() {
    int choice;

    do {
        printMenu();
        std::cin >> choice;

        try {
            switch (choice) {
                case 1:
                    runExample("simple_directed.txt");
                    break;
                case 2:
                    runExample("undirected_square.txt");
                    break;
                case 3:
                    runExample("disconnected_components.txt");
                    break;
                case 4:
                    runExample("cycles_and_self_loop.txt");
                    break;
                case 5:
                    runExample("dense_directed.txt");
                    break;
                case 6:
                    runExample("isolated_vertices.txt");
                    break;
                case 0:
                    std::cout << "Goodbye.\n";
                    break;
                default:
                    std::cout << "Invalid choice.\n\n";
            }
        } catch (const std::exception& error) {
            std::cout << error.what() << "\n\n";
        }
    } while (choice != 0);

    return 0;
}
