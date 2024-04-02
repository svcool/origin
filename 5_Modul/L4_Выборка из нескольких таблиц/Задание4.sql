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
SELECT mt.duration, s.pseudonym  FROM music_track mt 
JOIN album a ON a.id = mt.albumid 
JOIN album_singer as2 ON as2.albumid = a.id 
JOIN singer s ON s.id =	as2.singerid 
WHERE mt.duration = (SELECT MIN(mt.duration) FROM music_track mt);

--Названия альбомов, содержащих наименьшее количество треков.
WITH TrackCount AS (
    SELECT
        albumId,
        COUNT(id) AS NumberOfTracks
    FROM music_track
    GROUP BY albumId
),
MinTrackCount AS (
    SELECT MIN(NumberOfTracks) AS MinTracks
    FROM TrackCount
)
SELECT a.name_album
FROM album a
INNER JOIN TrackCount tc ON a.id = tc.albumId
INNER JOIN MinTrackCount mtc ON tc.NumberOfTracks = mtc.MinTracks;