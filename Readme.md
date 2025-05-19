# Raytracer

This document presents how the program works

## Launching the program
Linux:
```shell
$ git clone git@github.com:EpitechPromo2028/B-OOP-400-LYN-4-1-raytracer-ulysse.mercadal.git
```
> will clone the project

```shell
$ make
```
> will compile the project

```shell
$ ./raytracer [config file (.cfg)]
```
> will launch the project

## Architecture
```mermaid
classDiagram
    class RayTracer {
        -Simulation _simulation
        -string _configFileName
        -int _imageWidth
        -int _imageHeight
        +Run() void
    }

    class Simulation {
        -vector~Ray~ _rays
        -vector~rayTracer::IPrimitive~ _primitives
        -Camera _camera
        -PrimitiveFactory _factory
        +TraceRays() void
        +AddPrimitive(string type, params) void
        +CreateCamera(params) void
    }

    class PrimitiveFactory {
        +CreateSphere(Point, float, Material) Sphere
        +CreatePlane(Point, Vector, Material) Plane
        +CreateTriangle(Point[3], Material) Triangle
    }

    class Point {
        -float _x
        -float _y
        -float _z
    }

    class Vector {
        -float _x
        -float _y
        -float _z
    }

    class Color {
        -float _r
        -float _g
        -float _b
    }

    class Ray {
        -Point _origin
        -Vector _direction
        -Color _color
        +Trace(vector~rayTracer::IPrimitive~ primitives) Color
    }

    class Camera {
        -Point _position
        -Vector _WatchDirection
        -float _fov
        +GenerateRays(int width, int height) vector~Ray~
    }

    %% Primitive et Matériaux
    class rayTracer::IPrimitive {
        <<interface>>
        +intersect(Ray ray) bool
    }

    class Material {
        -Color _color
        -float _reflectivity
        -float _blurness
        ...more if needed in bonnuses
    }

    class Sphere {
        -Point _center
        -float _radius
        -Material material
        +intersect(Ray ray) bool
    }

    class Plane {
        -Point _referencePoint
        -Vector _normal
        -Material material
        +intersect(Ray ray) bool
    }

    RayTracer "1" --> "1" Simulation
    Simulation "1" --> "*" Ray
    Simulation "1" --> "1" PrimitiveFactory
    Simulation "1" --> "1" Camera
    Simulation "1" --> "*" rayTracer::IPrimitive

    PrimitiveFactory ..> Sphere : create
    PrimitiveFactory ..> Plane : create

    rayTracer::IPrimitive <|-- Sphere
    rayTracer::IPrimitive <|-- Plane

    Ray "1" --> "1" Point
    Ray "1" --> "1" Vector
    Ray "1" --> "1" Color

    Camera "1" --> "*" Ray

    Sphere "1" --> "1" Material
    Plane "1" --> "1" Material
```

## Configuration file
**Categories**
- camera (camera's informations):
    - postion (x, y, z)
    - rotation (x, y, z)
- image (generated image informations):
    - resolution (width, height)
    - format (output format)
    - fileName (output file path)
- graphical:
    - library (library used)
    - showRender (progressively displays the output on a GUI)
- processing:
    - rayDefinition (number of rays per pixel)
    - workers (number of threads working on the generation)
- primitives (list of primitives present in the scene, written in plurial)

## Extra
- You can add your own primitives by integrating new plugins. To do so, create a new directory in the `src/plugins` directory, with .cpp/.hpp files and a Makefile. Next, add your directory name in the `PLUGINS` variable in the file `src/plugins/Makefile` to compile your new plugin.
This plugin will have to be a class descending of the `APrimitive` class and integrating all mandatory methods of the class. To finish, you will only have to create a factory for your new primitive descending of the class `IFactory<IPrimitive>`. The only method you will have to override (and set as final by the way) is the `build` method, generating a shared pointer of your new primitive.

## Notes
- Note that you will need the `libconfig++` installed on your machine (version 1.8 or above)