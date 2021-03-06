#pragma once

class Box
{
	public:
		Vec lowerLeft;
		Vec topRight;

		Box(){}
		Box(const Vec & lowerLeft, const Vec & topRight) : lowerLeft(lowerLeft), topRight(topRight) {}
		Box(const Box & second) : lowerLeft(second.lowerLeft), topRight(second.topRight) {}
		
		Box & operator=(const Box & second)
		{
			lowerLeft = second.lowerLeft;
			topRight = second.topRight;
			return *this;
		}

		float surfaceArea() const
		{
			float dx = fabs(lowerLeft.x - topRight.x);	
			float dy = fabs(lowerLeft.y - topRight.y);
			float dz = fabs(lowerLeft.z - topRight.z);
			return 2.0 * dx * dy + 2.0 * dx * dz + 2.0 * dy * dz;
		}

		void setMin(int pk, float pe)
		{
			if (pk == 0)
				lowerLeft.x = pe;
			else if (pk == 1)
				lowerLeft.y = pe;
			else if (pk == 2)
				lowerLeft.z = pe;
		}

		void setMax(int pk, float pe)
		{
			if (pk == 0)
				topRight.x = pe;				
			else if (pk == 1)
				topRight.y = pe;
			else if (pk == 2)
				topRight.z = pe;
		}

		bool isPlanar()
		{
			if (lowerLeft.x == topRight.x)
				return true;
			else if (lowerLeft.y == topRight.y)
				return true;
			else if (lowerLeft.z == topRight.z)
				return true;
			return false;
		}

		float getMinValue(int dimension)
		{
			if (dimension == 0)
				return lowerLeft.x;
			else if (dimension == 1)
				return lowerLeft.y;
			else if (dimension == 2)
				return lowerLeft.z;
		}

		float getMaxValue(int dimension)
		{
			if (dimension == 0)
				return topRight.x;
			else if (dimension == 1)
				return topRight.y;
			else if (dimension == 2)
				return topRight.z;
		}

		void getVertices(std::vector<Vec> & vertices, std::vector<unsigned int> & order)
		{
			vertices.push_back(Vec(lowerLeft.x, lowerLeft.y, lowerLeft.z));
			vertices.push_back(Vec(topRight.x, lowerLeft.y, lowerLeft.z));
			vertices.push_back(Vec(topRight.x, topRight.y, lowerLeft.z));
			vertices.push_back(Vec(lowerLeft.x, topRight.y, lowerLeft.z));
			vertices.push_back(Vec(lowerLeft.x, lowerLeft.y, topRight.z));
			vertices.push_back(Vec(topRight.x, lowerLeft.y, topRight.z));
			vertices.push_back(Vec(topRight.x, topRight.y, topRight.z));
			vertices.push_back(Vec(lowerLeft.x, topRight.y, topRight.z));

			unsigned int s = order.size();
			std::vector<unsigned int> temp = 
			{
				s + 0, s + 1, s + 2, s + 3,
				s + 4, s + 5, s + 6, s + 7,
				s + 0, s + 4, s + 1, s + 5, s + 2, s + 6, s + 3, s + 7 	
			};

			for (int i = 0; i < temp.size(); ++i)	
				order.push_back(temp[i]);
		}

		friend std::ostream & operator<<(std::ostream & out, const Box & toPrint);
};




std::ostream & operator<<(std::ostream & out, const Box & toPrint)
{
	out << "Box Lower Left: " << toPrint.lowerLeft.x << " " << toPrint.lowerLeft.y << " " << toPrint.lowerLeft.z << std::endl;
	out << "Box Top Right: " << toPrint.topRight.x << " " << toPrint.topRight.y << " " << toPrint.topRight.z << std::endl;
	return out;
}
