--Названия альбомов, в которых присутствуют исполнители более чем одного жанра.
SELECT name_album, COUNT(g.name_genre) FROM album a
JOIN album_singer as2 ON a.id = as2.albumid 
JOIN singer s ON s.id = as2.singerid
JOIN genre_singer gs ON gs.singerid = s.id
JOIN genre g ON g.id = gs.genreid 
GROUP BY name_album
HAVING COUNT(g.name_genre) > 1;
--Наименования треков, которые не входят в сборники.
SELECT mt.name_track FROM collection c 
JOIN collection_track ct ON ct.collectionid  = c.id  
RIGHT JOIN music_track mt ON mt.id  = ct.trackid 
WHERE c.name_collection IS NULL
GROUP BY mt.name_track;

--Исполнитель или исполнители, написавшие самый короткий по продолжительности трек, — теоретически таких треков может быть несколько.
SELECT s.pseudonym, MIN(duration) FROM music_track mt 
JOIN album a ON a.id = mt.albumid 
JOIN album_singer as2 ON as2.albumid = a.id 
JOIN singer s ON s.id =	as2.singerid 
GROUP BY s.pseudonym, duration;
--Названия альбомов, содержащих наименьшее количество треков.
SELECT COUNT(mt.name_track), a.name_album FROM music_track mt 
JOIN album a ON a.id = mt.albumid 
JOIN album_singer as2 ON as2.albumid = a.id 
JOIN singer s ON s.id =	as2.singerid 
GROUP BY a.name_album 
ORDER BY COUNT(mt.name_track) ASC;