#include "../includes/vertex.hpp"

Vertex::Vertex()
{
	Node_type = "empty_str";
}

Vertex::~Vertex() {}

Vertex::Vertex(const std::smatch &result, options_of_construction var)
{
	if (var == left_node)
	{
		Node_type = result[1];
		Number_of_ports = result[2];
		Node_GUID = result[4];
		Port_GUID = result[5];
		SystemGUID = result[3];
		Node_description = result[9];
		LID = result[10];
		Vendor_ID = result[6];
		DeviceID = result[7];
		Revision = result[8];
		Link_State = result[26];
	}
	else
	{
		Node_type = result[12];
		Number_of_ports = result[13];
		Node_GUID = result[15];
		Port_GUID = result[16];
		SystemGUID = result[14];
		Node_description = result[20];
		LID = result[21];
		Vendor_ID = result[17];
		DeviceID = result[18];
		Revision = result[19];
		Link_State = result[26];
	}
}

std::ostream &operator<<(std::ostream &os, const Vertex &vertex)
{
	std::cout << "Node type        -> " << vertex.Node_type << std::endl;
	std::cout << "Number of ports  -> " << vertex.Number_of_ports << std::endl;
	std::cout << "Node GUID        -> " << vertex.Node_GUID << std::endl;
	std::cout << "Port GUID        -> " << vertex.Port_GUID << std::endl;
	std::cout << "Node description -> " << vertex.Node_description << std::endl;
	std::cout << "LID              -> " << vertex.LID << std::endl;

	return (os);
};
