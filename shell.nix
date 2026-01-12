{ pkgs ? import <nixpkgs> {}}:

pkgs.mkShell {
  packages = with pkgs; [ zlib curl.dev SDL2 SDL2_image openssl.dev cmake gnumake clang pkg-config ];
}
