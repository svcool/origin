--удаление данных сброс автоинкремента id

TRUNCATE TABLE public.album RESTART IDENTITY CASCADE;

TRUNCATE TABLE public.album_singer RESTART IDENTITY CASCADE;

TRUNCATE TABLE public.collection RESTART IDENTITY CASCADE;

TRUNCATE TABLE public.collection_track RESTART IDENTITY CASCADE;

TRUNCATE TABLE public.genre RESTART IDENTITY CASCADE;

TRUNCATE TABLE public.genre_singer RESTART IDENTITY CASCADE;

TRUNCATE TABLE public.music_track RESTART IDENTITY CASCADE;

TRUNCATE TABLE public.singer RESTART IDENTITY CASCADE;

INSERT INTO singer(pseudonym)
values('Louis Armstrong'), ('Seal'), ('Tina Turner'), ('Redbone');

INSERT INTO album(name_album, year_album)
values('album_Armstrong№1', '2000'), ('album_Seal№1', '2001' ), ('album_Tina Turner№1','2002'), ('albumRedbone№1','2005'),
('album_Armstrong№2', '2010'), ('album_Seal№1','2013'), ('album_Tina Turner№2','2014'), ('albumRedbone№2','2015'),
('album_Armstrong№3', '2021'), ('album_Seal№3', '2022'), ('album_Tina Turner№3', '2023'), ('albumRedbone№3', '2024');

INSERT INTO music_track(albumid, name_track, duration)
values(1, 'A kiss To Build a Вream', '00:01:35'), (1, 'La Vie En Rose№1', '00:08:25'), (2, 'Crazy', '00:04:45'), (2, 'Secret', '00:03:42'), (3, 'The Best','00:02:44'), (4, 'One More Time','00:01:44'), (4, 'Come and Get Your Love','00:05:15'),
(5, 'A kiss To Build a Вream on№2', '00:07:35'), (5, 'La Vie En Rose№2', '00:01:25'), (6, 'Crazy№2', '00:04:15'), (6, 'Secret№2', '00:03:22'),(7, 'The Best№2','00:02:34'), (8,'One More Time№2','00:01:46'), (8,'Come and Get Your Love№2','00:03:35'),
(9, 'A kiss To Build a Вream on№3', '00:03:23'), (9, 'La Vie En Rose№3', '00:01:15'), (10, 'Crazy№3', '00:04:45'), (10, 'Secret№3', '00:03:42'), (11, 'The Best№3','00:02:44'), (12,'One More Time№3','0:07:44'), (12,'Come and Get Your Love№3','00:08:25');

INSERT INTO genre(name_genre)
values('jazz'), ('vocal jazz'), ('pop'), ('rock');

INSERT INTO collection (id, name_collection, year_collection)
values(1,'collection№1','2000'), (2, 'collection№2','2021'), (3, 'collection№3','2023'), (4, 'collection№4','2023');

INSERT INTO collection_track(trackId, collectionId)
values(1,1),(18,1),(19,1),(20,1),(14,1),
(2,2),(5,2),(6,2),(7,2),(15,2),
(3,3),(8,3),(9,3),(10,3),(16,3),
(4,4),(11,4),(12,4),(13,4),(17,4);


INSERT INTO album_singer(albumid,singerid)
values(1,1), (5,1), (9,1),
(2,2), (6,2), (10,2),
(3,3), (7,3), (11,3),
(4,4), (8,4), (12,4);

INSERT INTO genre_singer(genreid,singerid)
values(1,1), (2,2), (2,1), (2,4), (1,3),
(3,3), (3,1), (1,2), (4,4), (4,3), (4,1);
