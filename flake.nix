{
  description = "December shader shell.";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }: 
  let 
    pkgs = nixpkgs.legacyPackages.x86_64-linux;
  in {
    devShells.x86_64-linux.default = pkgs.mkShell {
      packages = with pkgs; [
        ccls
        cmake
        ninja
        
        mesa
        libGL
        xorg.libX11
        xorg.libXcursor

        sdl3

        strace 
        gef
      ];
      
      LD_LIBRARY_PATH = pkgs.lib.makeLibraryPath [
        pkgs.libGL
        pkgs.xorg.libX11
        pkgs.xorg.libXcursor
        pkgs.mesa
      ];

      shellHook = ''
        echo "Entering December Shader shell!"
        echo "libGL: ${pkgs.libGL}"
      '';
    };

   packages.x86_64-linux.default = pkgs.stdenv.mkDerivation {
      name = "DecemberShader" ;
      pname = "decembershader";
      version = "1.0.0";
      src = ./.;

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
        cp $src/src/shader/src/fragment.frag $src/src/shader/src/vertex.vert $out/bin/data/
      '';
    };
  };
}
