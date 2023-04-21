#ifndef MGL_GEOMETRY_H
#define MGL_GEOMETRY_H

namespace mgl
{
	struct Rect
	{
	public:
		int x, y, w, h;

	public:
		Rect(const int x, const int y, const int w, const int h)
			: x(x), y(y), w(w), h(h)
		{

		}
	};

	struct Rectf
	{
	public:
		float x, y, w, h;

	public:
		Rectf(const float x, const float y, const float w, const float h)
			: x(x), y(y), w(w), h(h)
		{

		}
	};
}

#endif // MGL_GEOMTRY_H