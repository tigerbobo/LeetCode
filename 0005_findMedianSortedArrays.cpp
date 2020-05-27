double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
	int num_min, num_max;
	int size1, size2, offset1, offset2;
	int lmax1, lmax2, rmin1, rmin2;

	size1 = (int)(nums1.size());
	size2 = (int)(nums2.size());

	if (0 == size1)
	{
		size1 = 2;
		nums1.insert(nums1.begin(), nums2[0] - 1);
		nums1.insert(nums1.end(), nums2[size2 - 1] + 1);
	}

	if (0 == size2)
	{
		size2 = 2;
		nums2.insert(nums2.begin(), nums1[0] - 1);
		nums2.insert(nums2.end(), nums1[size1 - 1] + 1);
	}

	offset1 = size1 / 2;
	offset2 = (size1 + size2) / 2 - offset1;

	num_min = min(nums1[0], nums2[0]);
	num_max = max(*(nums1.end() - 1), *(nums2.end() - 1));

	while (true)
	{
		lmax1 = (offset1 - 1 >= 0) ? nums1[offset1 - 1] : num_min - 1;
		lmax2 = (offset2 - 1 >= 0) ? nums2[offset2 - 1] : num_min - 1;

		rmin1 = (offset1 < size1) ? nums1[offset1] : num_max + 1;
		rmin2 = (offset2 < size2) ? nums2[offset2] : num_max + 1;

		if (max(lmax1, lmax2) <= min(rmin1, rmin2))
			break;

		if (lmax1 > rmin2)
		{
			offset1 -= 1;
			offset2 += 1;
		}
		else if (lmax2 > rmin1)
		{
			offset1 += 1;
			offset2 -= 1;
		}
	}

	if ((size1 + size2) % 2)
		return (double)(min(rmin1, rmin2));
	else
		return (double)(max(lmax1, lmax2) + min(rmin1, rmin2)) / 2.0;
}
