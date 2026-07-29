# [III]BurstableTyres

IIIBurstableTyres is a plugin that brings the tyre popping feature from Vice City to GTA 3!


[GTAForums topic](https://gtaforums.com/topic/898955-burstable-tyres)

[YouTube demonstration](https://www.youtube.com/watch?v=Tkbh7M1xkZk)

# Installation

* Download the archive from [Releases section](https://github.com/Fire-Head/IIIBurstableTyres/releases)

* Extract `IIIBurstableTyres.asi` and `IIIBurstableTyres.ini` into your GTA 3 root or `scripts/` directory. If you using modloader put the files into a subdirectory inside the `modloader/`.

* To install sounds you have to edit `sfx.raw/sdt` manually(there is no other way, unfortunately, even modloader doesn't support loading `sfx.raw/sdt` samples outside their container).

1. Get [NullpointersGTA3SoundTools.zip](http://web.archive.org/web/20150509180640/http://pdescobar.home.comcast.net/~pdescobar/gta/NullpointersGTA3SoundTools.zip).
2. Create a new temporary directory and then copy original `sfx.RAW/SDT` into it, remove the "Read Only" attribute.
3. Extract `audext.exe/audimp.exe` from [NullpointersGTA3SoundTools.zip](http://web.archive.org/web/20150509180640/http://pdescobar.home.comcast.net/~pdescobar/gta/NullpointersGTA3SoundTools.zip) to the previously created directory.
4. Run `audext.exe`.
5. Extract .wav files from `III.BurstableTyres.7z/sfx` to the previously created directory.
6. Open `sfx.INF` with notepad, and replace each original line with an existing one from `III.BurstableTyres.7z/sfx/sfx settings.txt`(example: `sfx00370.wav 0 -1` -> `sfx00370.wav 0 22006`), save it.
7. Run `audimp.exe`.
8. Copy modified `sfx.RAW/SDT` to your `GTAIII/audio` directory or a subdirectory inside the `modloader/`.

# Supported game versions
* gta3.exe v1.0.
* gta3.exe v1.1.
* gta3.exe v1.1 Steam.


# Showcase
<img width="1920" height="1080" alt="image (4)" src="https://github.com/user-attachments/assets/d5d8fadc-3b85-4b09-9d8e-7d2021d57cb6" />
<img width="1920" height="1080" alt="image (3)" src="https://github.com/user-attachments/assets/b9cde28e-fac4-4b5b-89b3-713f70aa8b97" />
