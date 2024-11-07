#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

class Rect
{
    private:
        float width, height, x, y, rx, ry;
        std::string fill;
    public:
        Rect(const float width, const float height, const float x, const float y, const float rx, float ry, const std::string fill)
            : width(width), height(height), x(x), y(y), rx(rx), ry(ry), fill(fill) {}
    friend std::ostream& operator<<(std::ostream& os, const Rect& obj)
        {
            return os << "<rect width=\"" << std::to_string(obj.width) << "\" height=\"" << std::to_string(obj.height) << "\" x=\""
            << std::to_string(obj.x) << "\" y=\"" << std::to_string(obj.y) << "\" rx=\""
            + std::to_string(obj.rx) << "\" ry=\"" << std::to_string(obj.ry) << "\" fill=\"" << obj.fill << "\" />";
        }
};

class Line
{
    private:
        float x1, y1, x2, y2;
        std::string stroke;
        float stroke_width;
    public:
        Line(float x1, float y1, float x2, float y2, const std::string& stroke, int stroke_width)
    : x1(x1), y1(y1), x2(x2), y2(y2), stroke(stroke), stroke_width(stroke_width) {}
    friend std::ostream& operator<<(std::ostream& os, const Line& obj)
        {
            return os << "<line x1= \"" << std::to_string(obj.x1) << "\" y1= \"" << std::to_string(obj.y1) << "\" x2= \"" << std::to_string(obj.x2) << "\" y2= \"" << std::to_string(obj.y2)
            << "\" stroke = \"" << obj.stroke << "\" stroke-width = \"" << std::to_string(obj.stroke_width) << "\" />";
        }
};

class Polygon
{
    private:
        std::vector<std::pair<float, float>> vertices;
        float stroke_width;
        std::string fill;
    public:
        Polygon(const std::vector<std::pair<float, float>>& vertices, const std::string fill, float stroke_width)
            : vertices(vertices), fill(fill), stroke_width(stroke_width) {}
    friend std::ostream& operator<<(std::ostream& os, const Polygon& obj)
        {
            os << "<polygon points=\"";
            for (int i = 0; i < obj.vertices.size(); i++)
            {
                os << obj.vertices[i].first << "," << obj.vertices[i].second << " ";
            }
            os << "\" fill=\"" << obj.fill << "\" stroke-width=\"" << obj.stroke_width << "\"/>";\
            return os;
        }
};

int main(int argc, char* argv[])
{
    //Objects
    Rect rect1(70, 94, 0, 0, 1, 1, "#99856d");
    Line line1(0, 0, 70, 0, "black", 2);
    Line line2(0, 0, 0, 94, "black", 2);
    Line line3(0, 94, 70, 94, "black", 2);
    Line line4(70, 0, 70, 94, "black", 2); //final line
    Rect rect2(20, 10, 15, 20, 2, 6, "");
    
    std::vector<std::pair<float, float>> triangleVertices = {{33, 29.89}, {45, 28}, {38, 18}};
    Polygon triangle1(triangleVertices, "", 1);
    
    Rect rect3(10, 12, 43, 18.5, 1, 6, "");

    triangleVertices = {{25,20}, {42.5,15}, {36,14}};
    Polygon triangle2(triangleVertices, "", 1);

    std::vector<std::pair<float, float>> fourSidesVertices = {{25,20}, {45,20}, {42.5,20}, {42.54,14.88}};
    Polygon fourSides1(fourSidesVertices, "", 0.5);

    Rect rect4(20, 8, 28, 19, 1, 1, "");

    triangleVertices = {{48,19}, {42.5,14.5}, {42.5,19}};
    Polygon triangle3(triangleVertices, "", 0);

    triangleVertices = {{47,19}, {52.5,14.5}, {53.2,20}};
    Polygon triangle4(triangleVertices, "", 0);

    triangleVertices = {{43,15.3}, {46.5,16.4}, {47.2,19}};
    Polygon triangle5(triangleVertices, "", 0);

    triangleVertices = {{52,15.3}, {48.5,16.4}, {47.8,19}};
    Polygon triangle6(triangleVertices, "", 0);

    Rect rect5(3, 2, 46, 16.8, 1, 1, "");


    Rect rect6(70, 94, 0, 0, 1, 1, "");
    //---------------------------------------------------------------
    std::ofstream file("image.svg");

    file << "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 70 94\" width=\"350\" height=\"470\">\n";

    file << rect1 << "\n";
    file << line1 << "\n";
    file << line2 << "\n";
    file << line3 << "\n";
    
    file << "<g fill = \"#383129\" stroke = \"#383129\">\n";
    file << rect2 << "\n";
    file << triangle1 << "\n";
    file << rect3 << "\n";
    file << triangle2 << "\n";
    file << fourSides1 << "\n";
    file << rect4 << "\n";
    file << "<path d=\"M 42.5 14.5 C 45 17, 50 17, 52.5 14.5\" fill=\"transparent\" stroke-width=\"0.2\"/>\n";
    file << triangle3 << "\n";
    file << triangle4 << "\n";
    file << triangle5 << "\n";
    file << triangle6 << "\n";
    file << rect5 << "\n";
    file << "</g>\n";

    file << "<defs>\n<clipPath id=\"myClip\">\n";
    file << rect6 << "\n";
    file << "</clipPath>\n</defs>\n";

    file << "<g fill = \"#383129\" stroke = \"#383129\" transform=\"scale(1.7) translate(-5.5, 15)\">\n";
    file << rect2 << "\n";
    file << triangle1 << "\n";
    file << rect3<< "\n";
    file << triangle2 << "\n";
    file << fourSides1 << "\n";
    file << rect4 << "\n";
    file << "<path d=\"M 42.5 14.5 C 45 17, 50 17, 52.5 14.5\" fill=\"transparent\" stroke-width=\"0.2\"/>\n";
    file << triangle3 << "\n";
    file << triangle4 << "\n";
    file << triangle5 << "\n";
    file << triangle6 << "\n";
    file << rect5 << "\n";
    file << "</g>\n";
    
    file << line4 << "\n";
    file << "</svg>";
    file.close();
    return 0;
}