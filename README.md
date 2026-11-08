# UppGeometry

Modular 2D/3D Geometry Engine, Spatial Partitioning, Camera Projections, and Mesh Pipelines for the U++ Ecosystem.

Part of the [OuluBSD](https://github.com/OuluBSD) project.

---

## Overview

`UppGeometry` provides foundational 2D/3D mathematics and 3D asset pipeline tools decoupled from monolithic dependencies:

| Component | Capabilities |
|---|---|
| **Vectors & Matrices** | `vec2`, `vec3`, `vec4`, `mat3`, `mat4`, SIMD/FastMath routines, coordinate frame conversions |
| **Quaternions** | `quat` rotation representation, slerp interpolation, conjugate/inverse, matrix conversions |
| **Bounding Volumes** | `BoundingBox` (AABB), sphere, frustum culling and containment testing |
| **Spatial Indexing** | Hierarchical `Octree` and `Quadtree` with recycler memory pooling |
| **Camera & Projection** | Perspective and orthographic projection models, uncamera raycasting |
| **Mesh & Models** | Multi-material `Model`, `Mesh`, vertex buffers, tangent calculation via MikkTSpace |
| **Asset Importers** | Embedded `assimp` and `tiny_gltf` supporting FBX, glTF 2.0, OBJ, Collada, 3DS, etc. |
| **Numeric Optimization** | Header-only `GeneticOptimizer` and Eigen 3 integration |

---

## Building & Verification

`UppGeometry` builds with [UppBuilder](https://github.com/OuluBSD/UppBuilder) across Linux, macOS, and Windows:

```bash
# Build and run geometry verification suite
uppbuilder tests/GeometryCheck -m CLANG --bazaarcore /path/to/BazaarCore -v
./bin/GeometryCheck
```

---

## Continuous Integration

`UppGeometry` maintains a 4-platform CI matrix:
- **Ubuntu Clang** (`CLANG`)
- **Ubuntu GCC** (`GCC`)
- **macOS Clang** (`CLANG_macOS`)
- **Windows MSVC** (`MSVS22x64`)

---

## License

BSD 2-Clause License (see [LICENSE](LICENSE)).
