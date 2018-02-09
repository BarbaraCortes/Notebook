/* Geometry template with double coordinates */

typedef struct Point {
	double x, y;
	
	Point() {}
	
	Point(double a, double b) {
		x = a;
		y = b;
	}
	
	Point operator+(const Point b) const {
		return Point(x+b.x, y+b.y);
	}
	
	Point operator-(const Point b) const {
		return Point(x-b.x, y-b.y);
	}
	
	double operator*(const Point b) const {
		return x*b.x + y*b.y;
	}
	
	double operator^(const Point b) const {
		return x*b.y - y*b.x;
	}

	bool operator==(const Point b) const {
		return ((x == b.x) && (y == b.y));
	}
	
	bool operator<(const Point b) const {
		if (x != b.x) return x < b.x;
		return y < b.y;
	}

	/* Another way to sort vectors counter-clockwise
	bool hf() const {
		if (y == 0) return (x > 0);
		return (y > 0);
	}
	
	bool operator<(const Point b) const {
		bool h1 = hf();
		bool h2 = b.hf();
		if (h1 != h2) return (h1 < h2);
		return (((*this)^b) > 0);
	} */
	
	double len() {
		return sqrt((*this) * (*this));
	}

	Point perp() {
		return Point(-y, x);
	}
	
	/* Distancia do ponto ate um segmento */
	double dist_segment(Point p, Point q) {
		Point r = *this;
		if ((r-p)*(q-p) >= 0 && (r-q)*(p-q) >= 0) {
			return abs((q-p)^(r-p))/(q-p).len();
		}
		else return min((r-p).len(), (r-q).len());
	}

	/* Distancia do ponto ate a reta com vetor diretor PQ */
	double dist_reta(Point p, Point q) {
		Point r = *this;
		return abs((r-p)^(q-p))/(q-p).len();
	}
	
	/* Distancia do ponto ate uma reta parametrizada */
	double dist_line(int a, int b, int c) {
		return abs(a*this->x + b*this->y + c) / sqrt(a*a + b*b);
	}
	
	/* Verifica se um ponto esta dentro de um segmento */
	bool inside_segment(Point p, Point q) {
		Point r = *this;
		return ((p-r) * (q-r) <= 0);
	}

} Point;

/* Transforma um segmento A->B numa reta parametrizada da forma ax + by + c = 0 */
void segment_to_line(Point A, Point AB, double &a, double &b, double &c) {
	a = AB.y;
	b = -AB.x;
	c = AB.x*A.y - AB.y*A.x; //c = AB ^ A;
} 

/* Cramer's rule: encontra o ponto de interseccao entre duas retas */
Point lines_intersection(int a1, int b1, int c1, int a2, int b2, int c2) {
	int x = (-c1*b2 + c2 * b1)/(a1*b2 - a2*b1);
	int y = (a1*(-c2) + a2 * c1)/(a1*b2 - a2*b1);

	return Point(x, y);
}

/* Encontra as coordenadas do centro de uma circunferencia inscrita num triangulo */
Point incenter(Point A, Point B, Point C) {
	double a = Point(C-B).len();
	double b = Point(C-A).len();
	double c = Point(A-B).len();
	
	double x = (a*A.x + b*B.x + c*C.x)/(a + b + c);
	double y = (a*A.y + b*B.y + c*C.y)/(a + b + c);

	return Point(x, y);
}

/* Dispositivo delta */
double area(vector <Point> v) {
	double area = 0.0;
	for (int i = 0; i < (int)v.size(); i++) 
		area += v[i] ^ v[(i+1) % v.size()];
	return abs(area/2.0);
}

/* Sorts vectors counterclockwise */
bool compare(Point& a, Point& b) {
	return ((a-pivot)^(b-pivot)) > 0;
}

/* Monotonic chain */
vector<Point> convex_hull(vector <Point> p) {
	if (p.size() <= 2) return p;

	int n = p.size(), k = 0;
	vector<Point> H(2*n);

	sort(p.begin(), p.end());

	for (int i = 0; i < n; i++) {
		while (k >= 2 and ((H[k-1]-H[k-2])^(p[i]-H[k-2])) <= 0.0) k--;
		H[k++] = p[i];
	}

	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t and ((H[k-1]-H[k-2])^(p[i]-H[k-2])) <= 0.0) k--;
		H[k++] = p[i];
	}

	H.resize(k-1);

	return H;
}