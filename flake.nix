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
        renderdoc
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

   packages.x86_64-linux.default = (import nix/derivations.nix {inherit pkgs;}).linux.debug;
   };
}
