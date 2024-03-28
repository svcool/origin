--DROP TABLE album CASCADE;

--DROP TABLE album_singer CASCADE;

--DROP TABLE collection CASCADE;

--DROP TABLE collection_track CASCADE;

--DROP TABLE genre CASCADE;

--DROP TABLE genre_singer CASCADE;

--DROP TABLE music_track CASCADE;

--DROP TABLE singer CASCADE;

--жанр
CREATE TABLE IF NOT EXISTS genre (
id SERIAL PRIMARY KEY, 
name_genre VARCHAR(60) UNIQUE NOT NULL
);
--альбом
CREATE TABLE IF NOT EXISTS album (
id SERIAL PRIMARY KEY, 
name_album VARCHAR(100) NOT NULL,
year_album INTEGER NOT NULL
CHECK (year_album >= 1901 AND year_album <= 2155)
);
--исполнитель
CREATE TABLE IF NOT EXISTS singer (
id SERIAL PRIMARY KEY, 
pseudonym VARCHAR(100) UNIQUE NOT NULL
);
--трэк
CREATE TABLE IF NOT EXISTS music_track (
id SERIAL PRIMARY KEY,
albumId INTEGER REFERENCES album(id),
name_track VARCHAR(100) NOT NULL,
duration time NOT NULL,
UNIQUE (albumId, name_track)
);
--сборник
CREATE TABLE IF NOT EXISTS collection (
id SERIAL PRIMARY KEY, 
name_collection VARCHAR(100) NOT NULL,
year_collection INTEGER NOT NULL,
UNIQUE (name_collection, year_collection),
CHECK (year_collection >= 1901 AND year_collection <= 2155)
);
--жанр_исполнитель
CREATE TABLE IF NOT EXISTS genre_singer (
genreId INTEGER REFERENCES genre(id),
singerId INTEGER REFERENCES singer(id),
CONSTRAINT pk_genre_singer primary key(genreId, singerId)
);
--альбом_исполнитель
CREATE TABLE IF NOT EXISTS album_singer (
albumId INTEGER REFERENCES album(id),
singerId INTEGER REFERENCES singer(id),
CONSTRAINT pk_album_singer primary key(albumId, singerId)
);
--коллекция_трек
CREATE TABLE IF NOT EXISTS collection_track (
trackId INTEGER REFERENCES music_track(id),
collectionId INTEGER REFERENCES collection(id),
CONSTRAINT pk_collection_track primary key(collectionId , trackId)
);
