{ pkgs }:

{
  linux = {
    debug = pkgs.stdenv.mkDerivation {
      name = "DecemberShader" ;
      pname = "decembershader";
      version = "1.0.0";
      src = ../.;
      dontStrip = true;

      nativeBuildInputs = with pkgs; [
        cmake
        ninja
        sdl3
      ];

      buildInputs = with pkgs; [
        sdl3
        mesa
        libGL
        xorg.libX11
        xorg.libXcursor
      ];
      
      cmakeFlags = [
        "-DCMAKE_BUILD_TYPE=Debug"
      ];

      installPhase = ''
        mkdir -p $out/bin/data 
        cp decembershader $out/bin
        cp $src/src/opengl/src/fragment.frag $src/src/opengl/src/vertex.vert $out/bin/data/
      '';
    };
  };
}
