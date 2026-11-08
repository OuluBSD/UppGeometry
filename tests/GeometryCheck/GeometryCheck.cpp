#include <Core/Core.h>
#include <Geometry/Geometry.h>

using namespace Upp;

CONSOLE_APP_MAIN
{
	StdLogSetup(LOG_COUT | LOG_FILE);
	SetExitCode(0);

	Cout() << "Running GeometryCheck..." << EOL;

	// 1. Vector Operations
	{
		vec3 v1(1.0f, 2.0f, 3.0f);
		vec3 v2(4.0f, 5.0f, 6.0f);

		vec3 sum = v1 + v2;
		ASSERT(sum.data[0] == 5.0f && sum.data[1] == 7.0f && sum.data[2] == 9.0f);

		float dot = v1.Dot(v2);
		ASSERT(abs(dot - 32.0f) < 0.0001f);

		vec3 cross = v1.GetCrossProduct(v2);
		// (2*6 - 3*5, 3*4 - 1*6, 1*5 - 2*4) = (-3, 6, -3)
		ASSERT(abs(cross.data[0] - (-3.0f)) < 0.0001f);
		ASSERT(abs(cross.data[1] - (6.0f)) < 0.0001f);
		ASSERT(abs(cross.data[2] - (-3.0f)) < 0.0001f);

		float len = v1.GetLength();
		ASSERT(abs(len - sqrtf(14.0f)) < 0.0001f);

		Cout() << "  Vector operations passed" << EOL;
	}

	// 2. Matrix Operations
	{
		mat4 m;
		m.SetIdentity();
		ASSERT(m[0][0] == 1.0f && m[1][1] == 1.0f && m[2][2] == 1.0f && m[3][3] == 1.0f);

		mat4 t;
		t.SetTranslate(10.0f, 20.0f, 30.0f);
		vec3 trans = t.GetTranslation();
		ASSERT(abs(trans.data[0] - 10.0f) < 0.0001f);
		ASSERT(abs(trans.data[1] - 20.0f) < 0.0001f);
		ASSERT(abs(trans.data[2] - 30.0f) < 0.0001f);

		mat4 inv = t.GetInverse();
		vec3 inv_trans = inv.GetTranslation();
		ASSERT(abs(inv_trans.data[0] - (-10.0f)) < 0.001f);
		ASSERT(abs(inv_trans.data[1] - (-20.0f)) < 0.001f);
		ASSERT(abs(inv_trans.data[2] - (-30.0f)) < 0.001f);

		Cout() << "  Matrix operations passed" << EOL;
	}

	// 3. Quaternions
	{
		quat q1;
		q1.SetIdentity();
		ASSERT(q1.data.data[3] == 1.0f);

		quat inv = q1.GetInverse();
		ASSERT(inv.data.data[3] == 1.0f);

		Cout() << "  Quaternion operations passed" << EOL;
	}

	// 4. Bounding Box
	{
		BoundingBox box(vec3(-5, -5, -5), vec3(5, 5, 5));
		ASSERT(box.Contains(vec3(0, 0, 0)));
		ASSERT(!box.Contains(vec3(10, 0, 0)));

		vec3 dims = box.GetDimensions();
		ASSERT(abs(dims.data[0] - 10.0f) < 0.0001f);
		ASSERT(abs(dims.data[1] - 10.0f) < 0.0001f);
		ASSERT(abs(dims.data[2] - 10.0f) < 0.0001f);

		vec3 center = box.GetCenter();
		ASSERT(abs(center.data[0]) < 0.0001f);
		ASSERT(abs(center.data[1]) < 0.0001f);
		ASSERT(abs(center.data[2]) < 0.0001f);

		Cout() << "  Bounding box operations passed" << EOL;
	}

	// 5. Camera Projections
	{
		Camera cam;
		cam.SetPerspective(45.0f, 16.0f / 9.0f, 0.1f, 1000.0f);
		ASSERT(cam.IsPerspective());
		ASSERT(!cam.IsOrthographic());

		mat4 proj = cam.GetProjectionMatrix();
		ASSERT(!proj.IsNull());

		Cout() << "  Camera operations passed" << EOL;
	}

	// 6. Mesh Creation & Hash
	{
		Mesh mesh;
		Vertex v1, v2, v3;
		v1.Set(0, 0, 0);
		v2.Set(1, 0, 0);
		v3.Set(0, 1, 0);
		mesh.vertices.Add(v1);
		mesh.vertices.Add(v2);
		mesh.vertices.Add(v3);
		mesh.indices.Add(0);
		mesh.indices.Add(1);
		mesh.indices.Add(2);

		ASSERT(mesh.vertices.GetCount() == 3);
		ASSERT(mesh.indices.GetCount() == 3);
		ASSERT(mesh.GetHashValue() != 0);

		Cout() << "  Mesh creation passed" << EOL;
	}

	Cout() << "GeometryCheck: ALL CHECKS PASSED!" << EOL;
}
