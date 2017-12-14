#include "Canvas.h"

using namespace std;

Canvas :: Canvas(vector<string> _initCoordinates)
{
	initCoordinates = _initCoordinates;
	vector<string> groupPosition;
	groupPosition.push_back("0");
	groupPosition.push_back("0");
	mainGroup = new Group("", groupPosition, NULL);
}
void Canvas :: draw_a_shape(string shapeName, string shapeType, string CommandLine)
{
	vector<vector<string> > attributes = Rules::seperate_attributes(CommandLine); //A[0][0] = attname 
	try{
		for(int i=0; i<shapes.size(); i++)
			if(shapes[i] -> does_it(shapeName))
				throw BadException(NAME_EXISTS);
		if(shapeType == "circle")
			this -> draw_a_circle(shapeName, attributes);
		else if(shapeType == "rectangle")
			this -> draw_a_rectangle(shapeName, attributes);
		else if(shapeType == "line")
			this -> draw_a_line(shapeName, attributes);
		else if(shapeType == "text")
			this -> draw_a_text(shapeName, attributes);
	}
	catch(BadException ex){
		ex.print_msg();
	}
}
void Canvas :: draw_a_circle(string shapeName, vector<vector<string> > attributes)
{
	string radius="";
	vector<string> center;
	center.push_back("-2");
	center.push_back("-2");
	try{
		//find center and radius	
		for(int i=0; i<attributes.size(); i++)
		{
			if(attributes[i][0] == "center")
			{
				center = Rules::valid_coordinates(attributes[i][1]);
				if(center[0] == "-1" || center[1] == "-1")
					throw BadException(BAD_COOR_ERR);
				attributes.erase(attributes.begin() + i);
				i-- ;
			}
			else if(attributes[i][0] == "radius")
			{
				radius = attributes[i][1];
				attributes.erase(attributes.begin() + i);
				i-- ;
			}
		}
		if(radius=="" || center[0]=="-2" || center[1]=="-2")
			throw BadException(CIRCLE_ATT_NOT_FOUND);
		if(shapeName == "")
			shapeName = "circle" + this -> num_of_shapes_with_certian_type("circle");
		Circle* newCircle = new Circle(shapeName, mainGroup, radius, center);
		newCircle -> append_some_att(attributes);
		shapes.push_back(newCircle);
		cout<< "done!" << endl;
	}
	catch(BadException ex){
		ex.print_msg();
	}


}
string Canvas :: num_of_shapes_with_certian_type(string typeName)
{
	for(int i=0; i<shapes.size(); i++)
	{
		bool flag = false;
		for(int j=0; j<shapes.size(); j++)
		{
			if(shapes[j]->does_it(typeName + to_string(i)))
			{
				flag = true;
				break;
			}
		}
		if(flag == false)
		{
			return to_string(i);
		}
	}
	return to_string(shapes.size());
	
}
void Canvas :: draw_a_rectangle(string shapeName, vector<vector<string> > attributes)
{
	vector<vector<string> > points;
	vector<string> tmp;
	tmp.push_back("-2");
	tmp.push_back("-2");
	points.push_back(tmp);
	points.push_back(tmp);
	try
	{
		//find points
		for(int i=0; i<attributes.size(); i++)
		{
			if(attributes[i][0] == "points")
			{
				points = Rules::valid_array_of_coordinates(attributes[i][1]);
				if(points[0][0]=="-1" || points[0][1] == "-1" || points[1][0]=="-1" || points[1][1]=="-1")
					throw BadException(BAD_COOR_ERR);
				attributes.erase(attributes.begin() + i);
				i--;
			}
		}
		if(points[0][0]=="-2" || points[0][1] == "-2" || points[1][0]=="-2" || points[1][1]=="-2")
			throw BadException(REC_ATT_NOT_FOUND);
		if(shapeName == "")
			shapeName = "rectangle" + this -> num_of_shapes_with_certian_type("rectangle");
		Rectangle* newRec = new Rectangle(shapeName, mainGroup, points);
		newRec -> append_some_att(attributes);
		shapes.push_back(newRec);
		cout<< "done!" << endl;

	}
	catch(BadException ex){
		ex.print_msg();
	}

}
void Canvas :: draw_a_line(string shapeName, vector<vector<string> > attributes)
{
	vector<vector<string> > points;
	vector<string> tmp;
	tmp.push_back("-2");
	tmp.push_back("-2");
	points.push_back(tmp);
	points.push_back(tmp);
	try
	{
		//find points
		for(int i=0; i<attributes.size(); i++)
		{
			if(attributes[i][0] == "points")
			{
				points = Rules::valid_array_of_coordinates(attributes[i][1]);
				if(points[0][0]=="-1" || points[0][1] == "-1" || points[1][0]=="-1" || points[1][1]=="-1")
					throw BadException(BAD_COOR_ERR);
				attributes.erase(attributes.begin() + i);
				i--;
			}
		}
		if(points[0][0]=="-2" || points[0][1] == "-2" || points[1][0]=="-2" || points[1][1]=="-2")
			throw BadException(REC_ATT_NOT_FOUND);
		if(shapeName == "")
			shapeName = "line" + this -> num_of_shapes_with_certian_type("line");
		Line* newLine = new Line(shapeName, mainGroup, points);
		newLine -> append_some_att(attributes);
		shapes.push_back(newLine);
		cout<< "done!" << endl;
	}
	catch(BadException ex){
		ex.print_msg();
	}
}
void Canvas :: draw_a_text(string shapeName, vector<vector<string> > attributes)
{
	string text="";
	vector<string> position;
	position.push_back("-2");
	position.push_back("-2");
	try{
		//find position and text	
		for(int i=0; i<attributes.size(); i++)
		{
			if(attributes[i][0] == "position")
			{
				position = Rules::valid_coordinates(attributes[i][1]);
				if(position[0] == "-1" || position[1] == "-1")
					throw BadException(BAD_COOR_ERR);
				attributes.erase(attributes.begin() + i);
				i-- ;
			}
			else if(attributes[i][0] == "text")
			{
				text = attributes[i][1];
				attributes.erase(attributes.begin() + i);
				i-- ;
			}
		}
		if(position[0]=="-2" || position[1]=="-2")
			throw BadException(TEXT_ATT_NOT_FOUND);
		if(shapeName == "")
			shapeName = "text" + this -> num_of_shapes_with_certian_type("text");
		Text* newTxt = new Text(shapeName, mainGroup, text, position);
		newTxt -> append_some_att(attributes);
		shapes.push_back(newTxt);
		cout<< "done!" << endl;
	}
	catch(BadException ex){
		ex.print_msg();
	}
}
void Canvas :: make_a_group(string groupName, vector<vector<string> > attributes)
{
	vector<string> position; position.push_back("-2"); position.push_back("-2");
	bool inherit = DEFAULT;
	try
	{
		for(int i=0 ; i<groups.size(); i++)
			if(groups[i] -> does_it(groupName))
				throw BadException(NAME_EXISTS);
		for(int i=0; i<attributes.size(); i++)
		{
			if(attributes[i][0] == "position")
			{
				position = Rules::valid_coordinates(attributes[i][1]);
				if(position[0] == "-1" || position[1] == "-1")
					throw BadException(BAD_COOR_ERR);
				attributes.erase(attributes.begin() + i);
				i-- ;
			}
			else if(attributes[i][0] == "inherit")
			{
				if(attributes[i][1] == "default")
					inherit = DEFAULT;
				else if(attributes[i][1] == "force")
				{
					inherit = FORCE;
				}
				else 
					throw BadException(BAD_VALUE_FOR_INHERIT);
				attributes.erase(attributes.begin() + i);
				i-- ;
			}	
		}
		if(position[0]=="-2" || position[1]=="-2")
			throw BadException(GROUP_ATT_NOT_FOUND);
		if(groupName == "")
			groupName = "group" + this -> num_of_groups_without_name();
		Group* newGroup = new Group(groupName, position, mainGroup, inherit);
		newGroup -> append_some_att(attributes);
		groups.push_back(newGroup);
		cout << "done!" << endl;

	}
	catch(BadException ex){
		ex.print_msg();	
	}
}
string Canvas :: num_of_groups_without_name()
{
	for(int i=0; i<groups.size(); i++)
	{
		bool flag = false;
		for(int j=0; j<groups.size(); j++)
		{
			if(groups[j]->does_it("group" + to_string(i)))
			{
				flag = true;
				break;
			}
		}
		if(flag == false)
		{
			return to_string(i);
		}
	}
	return to_string(groups.size());
	
}
void Canvas :: delete_group(string groupName)
{
	try
	{
		Group* groupForDelete;
		bool exists = false;
		int index=0;
		for(int i=0; i<groups.size(); i++)
			if(groups[i]->does_it(groupName))
			{
				groupForDelete = groups[i];
				exists = true;
				break;
				index = i;
			}
		if(!exists)
			throw BadException(NAME_DOES_NOT_EXISTS);
		this -> delete_parent_for_all_shapes_and_groups(groupForDelete);
		groups.erase(groups.begin() + index);
		delete(groupForDelete);
		cout << "done!" << endl;
	}
	catch(BadException ex){
		ex.print_msg();
	}
}
void Canvas :: delete_parent_for_all_shapes_and_groups(Group* parent)
{
	for(int i=0; i<groups.size(); i++)
		if(groups[i]->get_parent() == parent)
			groups[i]->set_parent(parent->get_parent());
	
	for(int i=0; i<shapes.size(); i++)
		if(shapes[i]->get_parent() == parent)
			shapes[i]->set_parent(parent->get_parent());
}
void Canvas :: move(string objectName, string toGroupName)
{
	try
	{
		Group* toGroup = this -> find_to_group(toGroupName);
		bool gp = this -> move_group(objectName, toGroup);
		bool shape = this -> move_shape(objectName, toGroup);
		if(!gp && !shape)
			throw BadException(NO_OBJ_TO_MOVE);
		cout << "done!" << endl;
	}
	catch(BadException ex)
	{
		ex.print_msg();
	}
	
}
bool Canvas :: move_group(string groupName, Group* toGroup)
{
	try
	{
		bool exists = false;
		int index;
		for(int i=0; i<groups.size(); i++)
		{
			if(groups[i] -> does_it(groupName))
			{
				exists = true;
				index = i;
				break;
			}
		}
		if(!exists)
			throw BadException(NO_GP_TO_MOVE);
		groups[index]->set_parent(toGroup);
		return true;
	}
	catch(BadException ex){
		return false ;
	}

}
Group* Canvas :: find_to_group(string toGroupName)
{
	Group* toGroup = NULL;
	if(toGroupName == "")
		toGroup = mainGroup;
	else{
		bool exists = false;
		for(int i=0; i<groups.size(); i++)
		{
			if(groups[i] -> does_it(toGroupName))
			{
				exists = true;
				toGroup = groups[i];
				break;
			}
		}
		if(!exists)
			throw BadException(NO_GP);
	}
	return toGroup ;
}
bool Canvas :: move_shape(string shapeName, Group* toGroup)
{
	try
	{
		bool exists = false;
		int index;
		for(int i=0; i<shapes.size(); i++)
		{
			if(shapes[i] -> does_it(shapeName))
			{
				exists = true;
				index = i;
				break;
			}
		}
		if(!exists)
			throw BadException(NO_OBJ_TO_MOVE);
		shapes[index]->set_parent(toGroup);
		return true;
	}
	catch(BadException ex)
	{
		return false;
	}
}
void Canvas :: list(string groupName)
{
	try
	{
		Group* parent;
		if(groupName == "")
			parent = mainGroup;
		else 
			parent = this -> find_to_group(groupName);
		for(int i=0; i<groups.size() ; i++)
			if(groups[i]->get_parent() == parent)
				cout << groups[i]->get_name() << endl;
		for(int i=0; i<shapes.size() ; i++)
			if(shapes[i]->get_parent() == parent)
				cout << shapes[i]->get_name() << endl;
	}
	catch(BadException ex)
	{
		ex.print_msg();
	}
}
void Canvas :: export_to_file(string fileName)
{
	string backupFileName = fileName;
	Rules::get_sub_str_from_line(backupFileName, '.');
	string fileType = backupFileName;
	if(fileType == "svg")
	{
		SVGCreator ourSVGCreator(mainGroup, initCoordinates, shapes, groups);
		ourSVGCreator.make_svg(fileName);
	}
	cout << "done!"<<endl;
}
void Canvas :: bring_up(string objectName)
{
	for(int i=0 ; i<shapes.size(); i++)
	{
		if(shapes[i] -> does_it(objectName))
		{
			if(i!=0)
			{
				Shape* tmp = shapes[i-1];
				shapes[i-1] = shapes[i];
				shapes[i] = tmp ;
			}
		}
	}
	for(int i=0 ; i<groups.size(); i++)
	{
		if(groups[i] -> does_it(objectName))
		{
			if(i!=0)
			{
				Group* tmp = groups[i-1];
				groups[i-1] = groups[i];
				groups[i] = tmp ;
			}
		}
	}
	cout <<"done!"<<endl;
}
void Canvas :: bring_down(string objectName)
{
	for(int i=0 ; i<shapes.size(); i++)
	{
		if(shapes[i] -> does_it(objectName))
		{
			if(i!=shapes.size()-1)
			{
				Shape* tmp = shapes[i+1];
				shapes[i+1] = shapes[i];
				shapes[i] = tmp ;
			}
		}
	}
	for(int i=0 ; i<groups.size(); i++)
	{
		if(groups[i] -> does_it(objectName))
		{
			if(i!=groups.size()-1)
			{
				Group* tmp = groups[i+1];
				groups[i+1] = groups[i];
				groups[i] = tmp ;
			}
		}
	}
	cout << "done!" ;
}
void Canvas:: touch(string objectName, string att, string value)
{
	bool exists = false;
	for(int i=0 ; i<groups.size(); i++)
	{
		if(groups[i] -> does_it(objectName))
		{
			exists = true;
			groups[i] -> change_att(att, value);
			break;
		}
	}
	if(!exists)
	{
		for(int i=0 ; i<shapes.size(); i++)
	{
		if(shapes[i] -> does_it(objectName))
		{
			if(i!=shapes.size()-1)
			{
				shapes[i] -> change_att(att, value);
			}
		}
	}
	}
	cout << "done!" << endl;

}