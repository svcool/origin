template <typename It, typename Fn>
void parallel_for_each(It begin, It end, Fn&& function)
{
    const auto diff = std::distance(begin, end);
    constexpr auto num_threads = 8;
    std::vector<std::future<void>> fts;
    for (int i = 0; i < num_threads; ++i)
    {
        auto l = [&function](auto b, const auto thread_id, const auto n
            , const auto d)
            {
                std::for_each(b + (thread_id * d / n)
                    , b + ((thread_id + 1) * d / n), function);
            };
        fts.push_back(std::async(std::launch::async, l, begin, i, num_threads
            , diff));
    }
    for (auto& f : fts)
    {
        f.get();
    }
}