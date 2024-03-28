--Количество исполнителей в каждом жанре.
SELECT name_genre, COUNT(*) FROM genre g
JOIN genre_singer gs ON gs.genreid = g.id 
JOIN singer s ON gs.singerid  = s.id 
GROUP BY name_genre;

--Количество треков, вошедших в альбомы 2019–2020 годов.
SELECT COUNT(*) FROM music_track mt
JOIN album a ON mt.albumid = a.id  
WHERE a.year_album BETWEEN 2019 AND 2023
GROUP BY ROLLUP(name_track)
ORDER BY name_track DESC
LIMIT 1;

--Средняя продолжительность треков по каждому альбому.
SELECT a.name_album, AVG(duration) FROM music_track mt 
JOIN album a ON mt.albumid = a.id 
GROUP BY a.name_album 

--Все исполнители, которые не выпустили альбомы в 2020 году.
SELECT pseudonym FROM singer s 
JOIN album_singer as2 ON as2.singerid  = s.id 
JOIN album a ON a.id = as2.albumid 
WHERE a.year_album != 2020
GROUP BY pseudonym;

--Названия сборников, в которых присутствует конкретный исполнитель (выберите его сами
SELECT pseudonym, a.name_album FROM singer s
JOIN album_singer as2 ON as2.singerid = s.id
JOIN album a ON a.id = as2.albumid 
WHERE pseudonym  LIKE 'Seal'
GROUP BY pseudonym, a.name_album ;